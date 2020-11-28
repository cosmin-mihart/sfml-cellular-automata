#include <iostream>
#include<sstream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "GameOfLife.hpp"

int main()
{
    float windowWidthF = 1920.0f;
    unsigned windowWidthU = static_cast<unsigned>(windowWidthF);
    float windowHeightF = 1080.0f;
    unsigned windowHeightU = static_cast<unsigned>(windowHeightF);

    float cellSizeF = 10.0f;
    unsigned cellSizeU = static_cast<unsigned>(cellSizeF);

    unsigned gridWidth = windowWidthU/cellSizeU;
    unsigned gridHeight = windowHeightU/cellSizeU;

    bool simulationPause = false;
    bool inCreationMode = false;

    sf::RenderWindow window(sf::VideoMode(windowWidthU, windowHeightU), "Cellular automata");

    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;
    sf::Vector2u mousePosGrid;
    window.setFramerateLimit(30);


    sf::View view;
	view.setSize(windowWidthF, windowHeightF);
	view.setCenter(window.getSize().x / 2.f, window.getSize().y / 2.f);

    // Tile outline used for highlighting the tile under the mouse
    sf::RectangleShape tileSelector(sf::Vector2f(cellSizeF, cellSizeF));
	tileSelector.setFillColor(sf::Color::Transparent);
	tileSelector.setOutlineThickness(1.f);
	tileSelector.setOutlineColor(sf::Color::Green);

    sf::Text gridLocation;
    sf::Font font;
    font.loadFromFile("fonts/Roboto-Regular.ttf");
    gridLocation.setFont(font);
    gridLocation.setFillColor(sf::Color::Red);
    gridLocation.setCharacterSize(24);

    // Game of life object
    GameOfLife gameMap(cellSizeU, gridWidth, gridHeight, window);
    gameMap.generateMap();
    gameMap.updateMap();
    gameMap.updateMap();

    // TODO finde better way to run the app
    // and create a menu system
    while(window.isOpen())
    {
        window.clear();

        // Window events
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                break;

                case sf::Event::KeyPressed:
                    switch (event.key.code)
                    {
                        case sf::Keyboard::Space:
                            simulationPause = !simulationPause;
                        break;

                        case sf::Keyboard::C:
                        {
                            inCreationMode = !inCreationMode;
                            simulationPause = true;
                            gameMap.createCustomMap();
                        }
                    }
                case sf::Event::MouseButtonPressed:
                    switch (event.mouseButton.button)
                    {
                        case sf::Mouse::Left:
                            if (inCreationMode == true && simulationPause == true)
                                gameMap.cellCycle(mousePosGrid.x, mousePosGrid.y);
                    }
            }
        }

        // Get mouse position relative to view and grid
        mousePosWindow = sf::Mouse::getPosition(window);
		mousePosView = window.mapPixelToCoords(mousePosWindow);
        mousePosGrid.x = mousePosView.x / cellSizeU;
        mousePosGrid.y = mousePosView.y / cellSizeU;

        std::stringstream mousePosition;
        mousePosition << "Current cell: " << mousePosGrid.x << ", " << mousePosGrid.y;
        gridLocation.setString(mousePosition.str());

		window.setView(view);

        // Render game elements
        gameMap.showMap();
        if (simulationPause == false)
            gameMap.updateMap();

		window.setView(window.getDefaultView());

        // Render UI
		tileSelector.setPosition(mousePosGrid.x * cellSizeF, mousePosGrid.y * cellSizeF);
        window.draw(tileSelector);
        window.draw(gridLocation);

        // Display rendered items
        window.display();
    }

    return 0;
}

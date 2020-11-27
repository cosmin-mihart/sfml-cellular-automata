#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "GameOfLife.hpp"

int main()
{
    float windowWidthF = 1920.0f;
    unsigned windowWidthU = static_cast<unsigned>(windowWidthF);
    float windowHeightF = 1080.0f;
    unsigned windowHeightU = static_cast<unsigned>(windowHeightF);

    float cellSizeF = 6.0f;
    unsigned cellSizeU = static_cast<unsigned>(cellSizeF);

    unsigned gridWidth = windowWidthU/cellSizeU;
    unsigned gridHeight = windowHeightU/cellSizeU;

    bool simulationPause = false;

    sf::RenderWindow window(sf::VideoMode(windowWidthU, windowHeightU), "Cellular automata");

    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;
    sf::Vector2u mousePosGrid;
    window.setFramerateLimit(60);


    GameOfLife gameMap(cellSizeU, gridWidth, gridHeight, window);

    sf::View view;
	view.setSize(windowWidthF, windowHeightF);
	view.setCenter(window.getSize().x / 2.f, window.getSize().y / 2.f);

    sf::RectangleShape tileSelector(sf::Vector2f(cellSizeF, cellSizeF));
	tileSelector.setFillColor(sf::Color::Transparent);
	tileSelector.setOutlineThickness(1.f);
	tileSelector.setOutlineColor(sf::Color::Green);

    gameMap.generateMap();
    gameMap.updateMap();
    gameMap.updateMap();
    while(window.isOpen())
    {
        window.clear();
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::N && simulationPause == true)
                    gameMap.updateMap();
            }

            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Space)
                    simulationPause = !simulationPause;
            }
        }

        mousePosWindow = sf::Mouse::getPosition(window);
		window.setView(view);

		mousePosView = window.mapPixelToCoords(mousePosWindow);
        mousePosGrid.x = mousePosView.x / cellSizeU;
        mousePosGrid.y = mousePosView.y / cellSizeU;
		window.setView(window.getDefaultView());

        gameMap.showMap();
        if (simulationPause == false)
            gameMap.updateMap();

		tileSelector.setPosition(mousePosGrid.x * cellSizeF, mousePosGrid.y * cellSizeF);

        window.draw(tileSelector);
        window.display();
    }

    return 0;
}

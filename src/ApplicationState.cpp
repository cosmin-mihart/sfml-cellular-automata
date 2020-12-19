#include "ApplicationState.hpp"

ApplicationState::ApplicationState(sf::RenderWindow* window, std::stack<State*>* states) : State(window, states)
{
    this -> applicationMode = RUNNING;
    this -> cellSize = 10;
    this -> gameOfLife = new GameOfLife(this -> cellSize, this -> windowWidthU/this -> cellSize, this -> windowHeightU/this -> cellSize);
    this -> gameOfLife -> generateAutomaton();

    // Tile selector initialization
    // size needs to be cellSize - 1 to outline the cell
    this -> tileSelector.setSize(sf::Vector2f(this -> cellSize - 1, this -> cellSize - 1));
    this -> tileSelector.setFillColor(sf::Color::Transparent);
    this -> tileSelector.setOutlineThickness(2.0f);
    this -> tileSelector.setOutlineColor(sf::Color::Red);

    this -> initFonts();
    this -> currentApplicationMode.setFont(this -> font);
    this -> currentApplicationMode.setFillColor(sf::Color::Red);
    this -> currentApplicationMode.setCharacterSize(30);
    this -> currentApplicationMode.setPosition(10, 10);
}

ApplicationState::~ApplicationState()
{
    delete this -> gameOfLife;
}

void ApplicationState::endState()
{
    std::cout << "ending game state\n";
}

void ApplicationState::updateKeybinds(const float& deltaTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        this -> quitState();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
    {
            this -> applicationMode = PAUSED;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
            this -> applicationMode = RUNNING;
    }

}

void ApplicationState::updateState(const float& deltaTime)
{
    this -> updateMousePositions(this -> cellSize);
    this -> updateKeybinds(deltaTime);

    std::stringstream text;
    text << applicationMode;

    this -> currentApplicationMode.setString(text.str());
    switch (this -> applicationMode)
    {
        case RUNNING:
            this -> gameOfLife -> updateAutomaton();
        break;
        case PAUSED:
        break;
    }

    this -> tileSelector.setPosition(this -> mousePositionGrid.x * this -> cellSize, this -> mousePositionGrid.y * this -> cellSize);
}

void ApplicationState::renderState(sf::RenderTarget* target)
{
    this -> gameOfLife -> renderAutomaton(target);
    target -> draw(currentApplicationMode);
}

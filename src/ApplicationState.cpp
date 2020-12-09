#include "ApplicationState.hpp"

ApplicationState::ApplicationState(sf::RenderWindow* window, std::stack<State*>* states) : State(window, states)
{
    this -> applicationMode = RUNNING;
    this -> cellSize = 10;
    this -> test = new GameOfLife(this -> cellSize, this -> windowWidthU/this -> cellSize, this -> windowHeightU/this -> cellSize);
    this -> test -> generateAutomaton();
}

ApplicationState::~ApplicationState()
{
    delete this -> test;
}

void ApplicationState::endState()
{
    std::cout << "ending game state\n";
}

void ApplicationState::updateKeybinds(const float& deltaTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        this -> quitState();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        this -> applicationMode = EDITOR;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
    {
        if (this -> applicationMode == RUNNING)
            this -> applicationMode = PAUSED;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        if (this -> applicationMode == PAUSED)
            this -> applicationMode = RUNNING;
    }
}

void ApplicationState::updateState(const float& deltaTime)
{
    this -> updateKeybinds(deltaTime);
    switch (this -> applicationMode)
    {
        case RUNNING:
            this -> test -> updateAutomaton();
        break;
        case PAUSED:
            std::cout << "Simulation Running\n";
        break;
        case EDITOR:
            test -> createCustomAutomaton();
        break;
    }
}

void ApplicationState::renderState(sf::RenderTarget* target)
{
    this -> test -> renderAutomaton(target);
}

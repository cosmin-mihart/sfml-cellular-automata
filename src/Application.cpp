#include "Application.hpp"

void Application::initWindow()
{
    this -> windowWidth = sf::VideoMode::getDesktopMode().width;
    this -> windowHeight = sf::VideoMode::getDesktopMode().height;
    this -> windowTitle = "SFML Cellular Automata";
    this -> windowFramerate = 30;

    this -> window = new sf::RenderWindow(sf::VideoMode(this -> windowWidth, this -> windowHeight), this -> windowTitle, sf::Style::Fullscreen);
    this -> window -> setFramerateLimit(this -> windowFramerate);
}

void Application::initStates()
{
    this -> applicationStates.push(new MainMenuState(this -> window, &this -> applicationStates));
}

void Application::initApplication()
{
    this -> initWindow();
    this -> initStates();
}

Application::Application()
{
    this -> initApplication();
}

Application::~Application()
{
    delete this -> window;

    while (!this -> applicationStates.empty())
    {
        delete this -> applicationStates.top();
        this -> applicationStates.pop();
    }
}

// Application Methods

// Update deltaTime
// used for framerate independent gameplay
void Application::updateDeltaTime()
{
    this -> deltaTime = this -> deltaTimeClock.restart().asSeconds();
}

void Application::updateApplicationEvents()
{
    while (this -> window -> pollEvent(this -> applicationEvent))
    {
        if (this -> applicationEvent.type == sf::Event::Closed)
            this -> window -> close();
    }
}

void Application::updateApplication()
{
    this -> updateApplicationEvents();

    if (!this -> applicationStates.empty())
    {
        this -> applicationStates.top() -> updateState(this -> deltaTime);

        if (this -> applicationStates.top() -> getQuit())
        {
            this -> applicationStates.top() -> endState();
            delete this -> applicationStates.top();
            this -> applicationStates.pop();
        }
    }
    else
    {
        this -> endApplication();
    }
}

void Application::endApplication()
{
    std::cout << "closing application\n";
    this -> window -> close();
}

void Application::renderApplication()
{
    this -> window -> clear();
    // State rendering
    if (!this -> applicationStates.empty())
        this -> applicationStates.top() -> renderState(this -> window);

    this -> window -> display();;
}

void Application::runApplication()
{
    while (this -> window -> isOpen())
    {
        this -> updateDeltaTime();
        this -> updateApplication();
        this -> renderApplication();
    }
}

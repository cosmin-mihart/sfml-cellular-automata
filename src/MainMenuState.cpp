#include "MainMenuState.hpp"

MainMenuState::MainMenuState(sf::RenderWindow* window, std::stack<State*>* states) : State(window, states)
{
    this -> initFonts();
    this -> initButtons();
}

MainMenuState::~MainMenuState()
{
    for (auto button = this -> buttons.begin(); button != this -> buttons.end(); ++button)
    {
        delete button -> second;
    }
}

void MainMenuState::initButtons()
{
    this -> buttons["PLAY"] = new Button(400, 400, 150, 50, // Position and size
                                &this -> font, "Play", 30, // Font, font text and character size
                                sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(40, 40, 40, 200), // Button color
                                sf::Color::Yellow, sf::Color::White, sf::Color::Red, // Button text color
                                sf::Color::Yellow, sf::Color::White, sf::Color::Red); // Button outline color

    this -> buttons["QUIT"] = new Button(400, 600, 150, 50, // Position and size
                                &this -> font, "Exit", 30, // Font, font text and character size
                                sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(40, 40, 40, 200), // Button color
                                sf::Color::Yellow, sf::Color::White, sf::Color::Red, // Button text color
                                sf::Color::Yellow, sf::Color::White, sf::Color::Red); // Button outline color
}

void MainMenuState::updateButtons()
{
    for (auto &it : this -> buttons)
    {
        it.second -> updateButton(this -> mousePositionView);
    }

    if (this -> buttons["PLAY"] -> isActive())
    {
        this -> states -> push(new ApplicationState(this -> window, this -> states));
    }
    if (this -> buttons["QUIT"] -> isActive())
        this -> quitState();
}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
    for (auto &button : this -> buttons)
    {
        button.second -> renderButton(target);
    }
}

void MainMenuState::endState()
{
    std::cout << "ending game state\n";
}

void MainMenuState::updateKeybinds(const float& deltaTime)
{

}

void MainMenuState::updateState(const float& deltaTime)
{
    this -> updateMousePositions();
    this -> updateButtons();
    this -> updateKeybinds(deltaTime);


    std::stringstream mousePositions;
    mousePositions << this -> mousePositionWindow.x << ", " << this -> mousePositionWindow.y << "\n"
                << this -> mousePositionView.x << ", " << this -> mousePositionView.y;

    text.setString(mousePositions.str());
    text.setFont(this -> font);

    std::cout << "in main menu state\n";
}

void MainMenuState::renderState(sf::RenderTarget* target)
{
    target -> draw(text);
    this -> renderButtons(target);
}

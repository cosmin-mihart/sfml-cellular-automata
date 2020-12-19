#include "State.hpp"

State::State(sf::RenderWindow* window, std::stack<State*>* states)
{
    this -> window = window;
    this -> windowWidthF = this -> window -> getSize().x;
    this -> windowWidthU = static_cast<unsigned>(this -> windowWidthF);
    this -> windowHeightF = this -> window -> getSize().y;
    this -> windowHeightU = static_cast<unsigned>(this -> windowHeightF);

    this -> states = states;
    this -> quit = false;
}

State::~State()
{

}

const bool& State::getQuit() const
{
    return this -> quit;
}

void State::quitState()
{
    this -> quit = true;
}

void State::initFonts()
{
    if (!this -> font.loadFromFile("fonts/default.ttf"))
    {
        throw("ERROR: no font file found");
    }
}

void State::updateMousePositions(unsigned gridSize)
{
    this -> mousePositionScreen = sf::Mouse::getPosition();
    this -> mousePositionWindow = sf::Mouse::getPosition(*this -> window);
    this -> mousePositionView = this -> window -> mapPixelToCoords(sf::Mouse::getPosition(*this -> window));
    this -> mousePositionGrid.x = this -> mousePositionView.x/gridSize;
    this -> mousePositionGrid.y = this -> mousePositionView.y/gridSize;
}

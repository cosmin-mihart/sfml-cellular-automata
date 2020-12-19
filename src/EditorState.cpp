#include "EditorState.hpp"

EditorState::EditorState(sf::RenderWindow* window, std::stack<State*>* states):State(window, states)
{
    this -> gridSize = 30;
    this -> gameOfLifeEditor= new GameOfLife(this -> gridSize, this -> windowWidthU/this -> gridSize, this -> windowHeightU/this -> gridSize);
    this -> gameOfLifeEditor -> generateAutomaton();
    this -> gameOfLifeEditor -> createCustomAutomaton();
    this -> simulationPaused = false;
}

EditorState::~EditorState()
{
    delete this -> gameOfLifeEditor;
}

void EditorState::endState()
{
    std::cout << "Ending editor state";
}

void EditorState::updateKeybinds(const float& deltaTime)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this -> simulationPaused == true)
        this -> gameOfLifeEditor -> automatonCellState[this -> mousePositionGrid.x][this -> mousePositionGrid.y] = 1;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && this -> simulationPaused == true)
        this -> gameOfLifeEditor -> automatonCellState[this -> mousePositionGrid.x][this -> mousePositionGrid.y] = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        this -> simulationPaused = true;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        this -> simulationPaused = false;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        this -> quitState();
}

void EditorState::updateState(const float& deltaTime)
{
    this -> updateKeybinds(deltaTime);
    this -> updateMousePositions(this -> gridSize);
    if (simulationPaused == false)
        this -> gameOfLifeEditor -> updateAutomaton();
}

void EditorState::renderState(sf::RenderTarget* target)
{
    this -> gameOfLifeEditor -> renderAutomaton(target);
}

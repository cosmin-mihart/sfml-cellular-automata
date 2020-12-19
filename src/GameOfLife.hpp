#ifndef GAME_OF_LIFE_HPP
#define GAME_OF_LIFE_HPP

#include "CellularAutomaton.hpp"


// Class used to create game of life by Conway
class GameOfLife : public CellularAutomaton
{
public:
    GameOfLife(unsigned cellSize, unsigned gridWidth, unsigned gridHeight):CellularAutomaton(cellSize, gridWidth, gridHeight){};

    void resizeAutomaton(unsigned width, unsigned height, unsigned size) override;
    void generateAutomaton() override;
    void renderAutomaton(sf::RenderTarget* target) override;
    void updateAutomaton() override;
    void cellCycle(int x, int y) override;
    void createCustomAutomaton() override;
};

#endif

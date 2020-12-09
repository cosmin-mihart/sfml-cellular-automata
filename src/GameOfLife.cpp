#include "GameOfLife.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>

void GameOfLife::generateAutomaton()
{
    // Generate a random automaton
    srand(time(0));
    for (int x = 1; x < gridWidth - 1; x++)
        for (int y = 1; y < gridHeight - 1; y++)
            this -> automatonCellState[x][y] = rand() % 2;
}

void GameOfLife::renderAutomaton(sf::RenderTarget* target)
{
    // Change the color of the cells based on their state and render them
    for (int x = 0; x < this -> gridWidth; x++)
        for (int y = 0; y < this -> gridHeight; y++)
        {
            if (this -> automatonCellState[x][y] == 1) this -> automatonCell[x][y].setFillColor(sf::Color::White);
            else this -> automatonCell[x][y].setFillColor(sf::Color::Black);
            target -> draw(automatonCell[x][y]);
        }
    std::cout << "Shown rendered\n";
}

void GameOfLife::updateAutomaton()
{
    std::vector < std::vector < int>> tempAutomatonCellState;

    tempAutomatonCellState.resize(this -> gridWidth);
    for (int x = 0; x < this -> gridWidth; x++)
	{
        tempAutomatonCellState[x].resize(this -> gridHeight);
        for (int y = 0; y < this -> gridHeight; y++)
            tempAutomatonCellState[x][y] = this -> automatonCellState[x][y];
    }
    int numNeighbours;

    for (int x = 1; x < gridWidth - 1; x++)
        for (int y = 1; y < gridHeight - 1; y++)
        {
            // Get all the neighbours of a the cell matrix is bordered with 0
            // no special cases needed
            numNeighbours = tempAutomatonCellState[x - 1][y - 1] + tempAutomatonCellState[x - 1][y] +  tempAutomatonCellState[x - 1][y + 1] + tempAutomatonCellState[x][y - 1] +
                            tempAutomatonCellState[x][y + 1] + tempAutomatonCellState[x + 1][y - 1] + tempAutomatonCellState[x + 1][y] + tempAutomatonCellState[x + 1][y + 1];

            if (numNeighbours < 2) this -> automatonCellState[x][y] = 0;
            else if (numNeighbours == 3) this -> automatonCellState[x][y] = 1;
            else if (numNeighbours > 3) this -> automatonCellState[x][y] = 0;
        }

    std::cout << "Updated automaton\n";
}

void GameOfLife::cellCycle(int x, int y)
{
    this -> automatonCellState[x][y] = !this -> automatonCellState[x][y];
}

void GameOfLife::createCustomAutomaton()
{
    std::fill(this -> automatonCellState.begin(), this -> automatonCellState.end(), std::vector<int>(this -> gridHeight, 0));
}

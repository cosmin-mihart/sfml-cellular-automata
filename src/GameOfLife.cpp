#include "GameOfLife.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>

void GameOfLife::generateMap()
{
    srand(time(0));
    for (int x = 1; x < gridWidth - 1; x++)
        for (int y = 1; y < gridHeight - 1; y++)
            gameMapState[x][y] = rand() % 2;

    std::cout << "Generated game map\n";
}

void GameOfLife::showMap()
{
    for (int x = 0; x < gridWidth; x++)
        for (int y = 0; y < gridHeight; y++)
        {
            if (gameMapState[x][y] == 1) gameMap[x][y].setFillColor(sf::Color::Black);
            else gameMap[x][y].setFillColor(sf::Color::White);
            mWindow.draw(gameMap[x][y]);
        }
    std::cout << "Shown map\n";
}

void GameOfLife::updateMap()
{
    std::vector < std::vector < int>> tempMapState = gameMapState;

    int numNeighbours;

    for (int x = 1; x < gridWidth - 1; x++)
        for (int y = 1; y < gridHeight - 1; y++)
        {
            numNeighbours = tempMapState[x - 1][y - 1] + tempMapState[x - 1][y] +  tempMapState[x - 1][y + 1] + tempMapState[x][y - 1] +
                            tempMapState[x][y + 1] + tempMapState[x + 1][y - 1] + tempMapState[x + 1][y] + tempMapState[x + 1][y + 1];

            if (numNeighbours < 2) gameMapState[x][y] = 0;
            else if (numNeighbours == 3) gameMapState[x][y] = 1;
            else if (numNeighbours > 3) gameMapState[x][y] = 0;
        }

    std::cout << "Updated map\n";
}

void GameOfLife::cellCycle(int x, int y)
{
    gameMapState[x][y] = !gameMapState[x][y];
}

void GameOfLife::createCustomMap()
{
    std::fill(gameMapState.begin(), gameMapState.end(), std::vector<int>(gridHeight, 0));
}

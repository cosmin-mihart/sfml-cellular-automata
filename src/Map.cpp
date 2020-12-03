#include "Map.hpp"

#include <iostream>


Map::Map(unsigned cellSize, unsigned gridWidth, unsigned gridHeight, sf::RenderWindow& window):cellSize(cellSize), gridWidth(gridWidth), gridHeight(gridHeight), mWindow(window)
{
    gameMap.resize(gridWidth, std::vector<sf::RectangleShape>());
    gameMapState.resize(gridWidth);

    for (int x = 0; x < gridWidth; x++)
	{
		gameMap[x].resize(gridHeight, sf::RectangleShape());
        gameMapState[x].resize(gridHeight);

		for (int y = 0; y < gridHeight; y++)
		{
            gameMapState[x][y] = 0;
			gameMap[x][y].setSize(sf::Vector2f(cellSize, cellSize));
			gameMap[x][y].setFillColor(sf::Color::Black);
            gameMap[x][y].setOutlineThickness(0.5);
            gameMap[x][y].setOutlineColor(sf::Color(128, 128, 128, 255));
			gameMap[x][y].setPosition((x) * cellSize, (y) * cellSize);
		}
	}
};

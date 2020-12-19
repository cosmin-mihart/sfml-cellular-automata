#include "CellularAutomaton.hpp"

CellularAutomaton::CellularAutomaton(unsigned cellSize, unsigned gridWidth, unsigned gridHeight)
{
    this -> cellSize = cellSize;
    this -> gridWidth = gridWidth;
    this -> gridHeight = gridHeight;

    this -> automatonCell.resize(this -> gridWidth, std::vector<sf::RectangleShape>());
    this -> automatonCellState.resize(this -> gridWidth);

    for (int x = 0; x < this -> gridWidth; x++)
	{
		this -> automatonCell[x].resize(this -> gridHeight, sf::RectangleShape());
        this -> automatonCellState[x].resize(this -> gridHeight);

		for (int y = 0; y < this -> gridHeight; y++)
		{
            this -> automatonCellState[x][y] = 0;
			this -> automatonCell[x][y].setSize(sf::Vector2f(this -> cellSize, this -> cellSize));
			this -> automatonCell[x][y].setFillColor(sf::Color::Black);
            this -> automatonCell[x][y].setOutlineThickness(0.5);
            this -> automatonCell[x][y].setOutlineColor(sf::Color(128, 128, 128, 255));
			this -> automatonCell[x][y].setPosition((x) * this -> cellSize, (y) * this -> cellSize);
		}
	}
};

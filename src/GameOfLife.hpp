#ifndef GAME_OF_LIFE_HPP
#define GAME_OF_LIFE_HPP

#include "Map.hpp"

class GameOfLife : public Map
{
public:
    GameOfLife(unsigned cellSize, unsigned gridWidth, unsigned gridHeight, sf::RenderWindow& window ):Map(cellSize, gridWidth, gridHeight, window){};

    void generateMap() override;
    void showMap() override;
    void updateMap() override;
};

#endif

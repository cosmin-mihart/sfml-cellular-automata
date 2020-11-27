#ifndef MAP_HPP
#define MAP_HPP

#include <vector>
#include <SFML/Graphics.hpp>

struct game_map
{
    sf::RectangleShape tile;
    int state;
};

class Map
{
    public:
        unsigned cellSize, gridWidth, gridHeight;
        sf::RenderWindow& mWindow;
        std::vector < std::vector <sf::RectangleShape>> gameMap;
        std::vector < std::vector <int>> gameMapState;
    public:
        Map(unsigned cellSize, unsigned gridWidth, unsigned gridHeight, sf::RenderWindow& window);

        virtual void generateMap() = 0;
        virtual void showMap() = 0;
        virtual void updateMap() = 0;
};

#endif

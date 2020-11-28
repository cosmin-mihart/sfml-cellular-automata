#ifndef MAP_HPP
#define MAP_HPP

#include <vector>
#include <SFML/Graphics.hpp>

// Basic class used for implementing cellular automata
class Map
{
    public:
        unsigned cellSize, gridWidth, gridHeight;
        sf::RenderWindow& mWindow;
        std::vector < std::vector <sf::RectangleShape>> gameMap;
        std::vector < std::vector <int>> gameMapState;
    public:
        Map(unsigned cellSize, unsigned gridWidth, unsigned gridHeight, sf::RenderWindow& window);

        // Generate random game map
        virtual void generateMap() = 0;
        // Display the game map
        virtual void showMap() = 0;
        // Update game map
        virtual void updateMap() = 0;
        // Cycle trough cell states
        virtual void cellCycle(int x, int y) = 0;
        // Create and customize a game map
        virtual void createCustomMap() = 0;
};

#endif

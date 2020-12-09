#ifndef CELLULAR_AUTOMATON_HPP
#define CELLULAR_AUTOMATON_HPP

#include <vector>
#include <SFML/Graphics.hpp>

// Basic class used for implementing cellular automata
class CellularAutomaton
{
    public:
        unsigned cellSize, gridWidth, gridHeight;
        std::vector < std::vector <sf::RectangleShape>> automatonCell;
        std::vector < std::vector <int>> automatonCellState;
    public:
        CellularAutomaton(unsigned cellSize, unsigned gridWidth, unsigned gridHeight);

        // Generate random automaton
        virtual void generateAutomaton() = 0;
        // Advance one generation
        virtual void updateAutomaton() = 0;
        // Render current generation
        virtual void renderAutomaton(sf::RenderTarget* target) = 0;
        // Cycle trough cell states
        virtual void cellCycle(int x, int y) = 0;
        // Create and customize a game map
        virtual void createCustomAutomaton() = 0;
};

#endif

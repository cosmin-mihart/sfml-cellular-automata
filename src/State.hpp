#ifndef STATE_HPP
#define STATE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <vector>
#include <stack>
#include <map>
#include <string>

#include <iostream>
#include <fstream>
#include <sstream>

class State
{
    public:
        std::stack<State*>* states;
        sf::RenderWindow* window;
        bool quit;

        float windowWidthF;
        unsigned windowWidthU;
        float windowHeightF;
        unsigned windowHeightU;

        unsigned gridSize;

        sf::Font font;

        sf::Vector2i mousePositionScreen;
        sf::Vector2i mousePositionWindow;
        sf::Vector2f mousePositionView;
        sf::Vector2u mousePositionGrid;

    public:
        State(sf::RenderWindow* window, std::stack<State*>* states);
        virtual ~State();

        const bool& getQuit() const;
        virtual void quitState();

        virtual void initFonts();
        virtual void updateMousePositions(unsigned gridSize = 1);


        virtual void endState() = 0;
        virtual void updateKeybinds(const float& deltaTime) = 0;
        virtual void updateState(const float& deltaTime) = 0;
        virtual void renderState(sf::RenderTarget* target = nullptr) = 0;
};

#endif

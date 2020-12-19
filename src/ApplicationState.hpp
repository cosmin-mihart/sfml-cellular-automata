#ifndef APPLICATION_STATE_HPP
#define APPLICATION_STATE_HPP

#include "State.hpp"
#include "GameOfLife.hpp"

enum ApplicationMode { RUNNING, PAUSED };

class ApplicationState : public State
{
    private:
        unsigned cellSize;
        GameOfLife* gameOfLife;
        sf::RectangleShape tileSelector;
        sf::Text currentApplicationMode;

        ApplicationMode applicationMode;

    public:
        ApplicationState(sf::RenderWindow* window, std::stack<State*>* states);
        ~ApplicationState();

        void endState() override;
        void updateKeybinds(const float& deltaTime) override;
        void updateState(const float& deltaTime) override;
        void renderState(sf::RenderTarget* target = nullptr) override;
};

#endif

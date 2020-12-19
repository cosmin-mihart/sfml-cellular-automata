#ifndef EDITOR_STATE_HPP
#define EDITOR_STATE_HPP

#include "State.hpp"
#include "GameOfLife.hpp"

class EditorState : public State
{
    private:
        sf::RectangleShape tileSelector;
        GameOfLife* gameOfLifeEditor;
        bool simulationPaused;

    public:
        EditorState(sf::RenderWindow* window, std::stack<State*>* states);
        ~EditorState();

        void endState() override;
        void updateKeybinds(const float& deltaTime) override;
        void updateState(const float& deltaTime) override;
        void renderState(sf::RenderTarget* target = nullptr) override;
};

#endif

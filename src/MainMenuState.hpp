#ifndef MAIN_MENU_STATE_HPP
#define MAIN_MENU_STATE_HPP

#include "Button.hpp"
#include "ApplicationState.hpp"
#include "EditorState.hpp"

class MainMenuState : public State
{
    private:
        std::map<std::string, Button*> buttons;

    public:
        MainMenuState(sf::RenderWindow* window, std::stack<State*>* states);
        ~MainMenuState();

        void initButtons();
        void updateButtons();
        void renderButtons(sf::RenderTarget* target);

        void endState() override;
        void updateKeybinds(const float& deltaTime) override;
        void updateState(const float& deltaTime) override;
        void renderState(sf::RenderTarget* target = nullptr) override;
};

#endif

#ifndef GAME_HPP
#define GAME_HPP

#include "ApplicationState.hpp"
#include "MainMenuState.hpp"

class Application
{
    private:
        // Variables
        // Window default variables
        // used for testing if the config file is working
        sf::RenderWindow *window;
        int windowWidth = 800;
        int windowHeight = 800;
        std::string windowTitle = "something went wrong";
        int windowFramerate = 120;

        // Application events
        sf::Event applicationEvent;

        // Application states
        std::stack<State*> applicationStates;

        // Delta time
        sf::Clock deltaTimeClock;
        float deltaTime;

        void initWindow();
        void initStates();
        void initApplication();

    public:
        Application();
        virtual ~Application();

        void endApplication();

        void updateDeltaTime();
        void updateApplicationEvents();
        void updateApplication();
        void renderApplication();
        void runApplication();
};

#endif

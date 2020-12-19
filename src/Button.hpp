#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <string>

enum ButtonStates{BUTTON_IDLE = 0, BUTTON_HOVER, BUTTON_ACTIVE};

class Button
{
    private:
        sf::RectangleShape buttonShape;
        sf::Font* font;
        sf::Text buttonText;

        sf::Color buttonIdleColor;
        sf::Color buttonHoverColor;
        sf::Color buttonActiveColor;

        sf::Color buttonTextIdleColor;
        sf::Color buttonTextHoverColor;
        sf::Color buttonTextActiveColor;

        sf::Color buttonOutlineIdleColor;
        sf::Color buttonOutlineHoverColor;
        sf::Color buttonOutlineActiveColor;

        ButtonStates buttonState;

    public:
        Button();
        Button(float x, float y, float width, float height,
               sf::Font *font, std::string text, int characterSize,
               sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor,
               sf::Color textIdleColor, sf::Color textHoverColor, sf::Color textActiveColor,
               sf::Color outlineIdleColor, sf::Color outlineHoverColor, sf::Color outlineActiveColor);
        ~Button();

        const bool isActive() const;

        void updateButton(const sf::Vector2f mousePosition);
        void renderButton(sf::RenderTarget* target);
};

#endif

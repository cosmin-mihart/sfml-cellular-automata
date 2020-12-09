#include "Button.hpp"

Button::Button(){}
Button::Button(float x, float y, float width, float height,
               sf::Font *font, std::string text, int characterSize,
               sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor,
               sf::Color textIdleColor, sf::Color textHoverColor, sf::Color textActiveColor,
               sf::Color outlineIdleColor, sf::Color outlineHoverColor, sf::Color outlineActiveColor)
{
    this -> buttonShape.setPosition(sf::Vector2f(x, y));
    this -> buttonShape.setSize(sf::Vector2f(width, height));

    this -> font = font;
    this -> buttonText.setFont(*this -> font);
    this -> buttonText.setString(text);
    this -> buttonText.setFillColor(sf::Color::White);
    this -> buttonText.setCharacterSize(characterSize);
    sf::FloatRect textRect = this -> buttonText.getLocalBounds();
    buttonText.setOrigin(textRect.left + textRect.width/2.0f,
               textRect.top  + textRect.height/2.0f);
    buttonText.setPosition(x + buttonShape.getGlobalBounds().width/2, y + buttonShape.getGlobalBounds().height/2);

    this -> buttonIdleColor = idleColor;
    this -> buttonHoverColor = hoverColor;
    this -> buttonActiveColor = activeColor;

    this -> buttonTextIdleColor = textIdleColor;
    this -> buttonTextHoverColor = textHoverColor;
    this -> buttonTextActiveColor = textActiveColor;

    this -> buttonOutlineIdleColor = outlineIdleColor;
    this -> buttonOutlineHoverColor = outlineHoverColor;
    this -> buttonOutlineActiveColor = outlineActiveColor;

    this -> buttonShape.setFillColor(idleColor);
    this -> buttonShape.setOutlineThickness(1);
    this -> buttonShape.setOutlineColor(outlineIdleColor);
    this -> buttonText.setFillColor(textIdleColor);
}

Button::~Button()
{

}

const bool Button::isActive() const
{
    if (this -> buttonState == BUTTON_ACTIVE)
        return true;
    return false;
}


void Button::updateButton(const sf::Vector2f mousePosition)
{
    this -> buttonState = BUTTON_IDLE;
    if (this -> buttonShape.getGlobalBounds().contains(mousePosition))
    {
        this -> buttonState = BUTTON_HOVER;
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            this -> buttonState = BUTTON_ACTIVE;
    }

    switch(buttonState)
    {
        case BUTTON_IDLE:
        {
            this -> buttonShape.setFillColor(this -> buttonIdleColor);
            this -> buttonShape.setOutlineColor(this -> buttonOutlineIdleColor);
            this -> buttonText.setFillColor(this -> buttonTextIdleColor);
        }
            break;
        case BUTTON_HOVER:
        {
            this -> buttonShape.setFillColor(this -> buttonHoverColor);
            this -> buttonShape.setOutlineColor(this -> buttonOutlineHoverColor);
            this -> buttonText.setFillColor(this -> buttonTextHoverColor);
        }
            break;
        case BUTTON_ACTIVE:
        {
            this -> buttonShape.setFillColor(this -> buttonActiveColor);
            this -> buttonShape.setOutlineColor(this -> buttonOutlineActiveColor);
            this -> buttonText.setFillColor(this -> buttonTextActiveColor);
        }
            break;
    }
}

void Button::renderButton(sf::RenderTarget* target)
{
    target -> draw(this -> buttonShape);
    target -> draw(this -> buttonText);
}

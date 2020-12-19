#include "Application.hpp"

int main()
{
    //// Tile hilight used for highlighting the tile under the mouse
    // sf::RectangleShape tileSelector(sf::Vector2f(cellSizeF - 6, cellSizeF - 6));
	// tileSelector.setFillColor(sf::Color::Transparent);
	// tileSelector.setOutlineThickness(4.f);
	// tileSelector.setOutlineColor(sf::Color::Red);
    // tileSelector.setPosition(mousePosGrid.x * cellSizeF + 3, mousePosGrid.y * cellSizeF + 3);
    // window.draw(tileSelector);
    Application application;
    application.runApplication();

    return 0;
}

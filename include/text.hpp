#ifndef TEXT_HPP
#define TEXT_HPP

#include "textbuilder.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>

class Text
{
public:
    Text();

    void update(int points, std::size_t length);
    void draw(sf::RenderWindow& window, bool isGameOver);

private:
    enum TextType
    {
        PointsText,
        LengthText,
    };

    enum {arrayTextSz = 3};

    sf::Font font;
    std::array<sf::Text, arrayTextSz> texts;
};

#endif // TEXT_HPP

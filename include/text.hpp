#ifndef TEXT_HPP
#define TEXT_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>

enum {arrayTextSz = 3};

struct TextBuilder
{
    sf::Text operator()(sf::Text text)
    {
        float width = 530.f;
        static float height = 50.f;

        text.setFillColor(sf::Color(047, 69, 056));
        text.setCharacterSize(15);
        text.setPosition(width, height += 100);

        height += text.getGlobalBounds().height;

        static std::size_t count = 0;

        if(count == 2)
        {
            text.setFillColor(sf::Color::Red);
            text.setString("Game over!!!");
            text.setPosition(width, height - 100.f);
        }

        count++;

        return text;
    }
};

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
        GameOverText
    };

    sf::Font font;
    std::array<sf::Text, arrayTextSz> texts;
};

#endif // TEXT_HPP

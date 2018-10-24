#ifndef TEXTBUILDER_HPP
#define TEXTBUILDER_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class TextBuilder
{
public:
    TextBuilder(float w, float h, sf::Color c);

    sf::Text operator()(sf::Text);

private:
    sf::Color color;
    float width;
    float height;
};

#endif // TEXTBUILDER_HPP

#include "textbuilder.hpp"

TextBuilder::TextBuilder(float w, float h, sf::Color c) :
    width(w),
    height(h),
    color(c) { }

sf::Text TextBuilder::operator()(sf::Text text)
{
    text.setFillColor(color);
    text.setCharacterSize(15);
    text.setPosition(width, height += 100);

    height += text.getGlobalBounds().height;

    return text;
}

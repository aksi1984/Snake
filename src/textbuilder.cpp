#include "textbuilder.hpp"

TextBuilder::TextBuilder(float w, float h, int s, sf::Color c) :
    width(w),
    height(h),
    color(c),
    charSize(s) { }

sf::Text TextBuilder::operator()(sf::Text text)
{
    text.setFillColor(color);
    text.setCharacterSize(charSize);
    text.setPosition(width, height += 100);

    height += text.getGlobalBounds().height;

    return text;
}

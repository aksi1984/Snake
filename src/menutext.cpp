#include "menutext.hpp"

MenuText::MenuText() :
    TextBase(2, R"(Fonts\Super FamiFont.ttf)")
{
    std::transform(textVec.begin(), textVec.end(), textVec.begin(), TextBuilder(320, 100, 30, sf::Color::Blue));

    const std::size_t strArraySz = 2;
    std::array<std::string, strArraySz> strings{ "Play", "Exit" };

    std::transform( textVec.begin(), textVec.end(), textVec.begin(), [strings](sf::Text t){ static std::size_t c = 0; t.setString(strings.at(c++)); return t; } );
}

std::size_t MenuText::getSize() const
{
    return textVec.size();
}

sf::FloatRect MenuText::getGlobalBounds(std::size_t num) const
{
    return textVec.at(num).getGlobalBounds();
}

void MenuText::changeColor(std::size_t num, sf::Color color)
{
    textVec.at(num).setFillColor(color);
}

sf::Color MenuText::getColor(std::size_t num) const
{
    return textVec.at(num).getColor();
}

void MenuText::draw(sf::RenderWindow& window)
{
    for(auto x : textVec) window.draw(x);
}

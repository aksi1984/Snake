#ifndef MENUTEXT_HPP
#define MENUTEXT_HPP

#include "textbuilder.hpp"
#include "textbase.hpp"

class MenuText : public TextBase
{
public:
    MenuText();

    std::size_t getSize() const;
    sf::FloatRect getGlobalBounds(std::size_t num) const;
    void changeColor(std::size_t num, sf::Color color);
    sf::Color getColor(std::size_t num) const;
    void draw(sf::RenderWindow& window);
};

#endif // MENUTEXT_HPP

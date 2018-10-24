#ifndef GAMETEXT_HPP
#define GAMETEXT_HPP

#include "textbuilder.hpp"
#include "textbase.hpp"

class GameText : public TextBase
{
public:
    GameText();

    void update(int points, std::size_t length);
    void setNumTextToDisplay(bool isGameOver);
    void draw(sf::RenderWindow& window);

public:
    std::size_t numOfTextToDisplay;
};

#endif // TEXT_HPP

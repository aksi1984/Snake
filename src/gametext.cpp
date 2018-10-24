#include "gametext.hpp"

GameText::GameText() :
    TextBase(3, R"(Fonts\StalinistOne-Regular.ttf)"),
    numOfTextToDisplay(2)
{
    std::transform(textVec.begin(), textVec.end(), textVec.begin(), TextBuilder(530, 70, 15, sf::Color(047, 69, 056)));

    textVec.at(2).setString("Game over!!!");
    textVec.at(2).setFillColor(sf::Color::Red);
}

void GameText::update(int points, std::size_t length)
{
    textVec.at(0).setString("Points: " + std::to_string(points));
    textVec.at(1).setString("Length: " + std::to_string(length));
}

void GameText::setNumTextToDisplay(bool isGameOver)
{
    numOfTextToDisplay = ( isGameOver ? 3 : 2 );
}

void GameText::draw(sf::RenderWindow& window)
{
    for(std::size_t i = 0; i < numOfTextToDisplay; ++i)
    {
        window.draw(textVec.at(i));
    }
}

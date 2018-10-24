#include "text.hpp"

Text::Text()
{
    if(font.loadFromFile(R"(Fonts\StalinistOne-Regular.ttf)"))
    {
        std::transform(texts.begin(), texts.end(), texts.begin(), [this](sf::Text t){ t.setFont(font); return t; });
        std::transform(texts.begin(), texts.end(), texts.begin(), TextBuilder(530, 70, sf::Color(047, 69, 056)));

        texts.at(2).setString("Game over!!!");
        texts.at(2).setColor(sf::Color::Red);
    }
}

void Text::update(int points, std::size_t length)
{
    texts[TextType::PointsText].setString("Points: " + std::to_string(points));
    texts[TextType::LengthText].setString("Length: " + std::to_string(length));
}

void Text::draw(sf::RenderWindow& window, bool isGameOver)
{
    std::size_t numOfTextToDisplay = ( isGameOver ? 3 : 2 );

    for(std::size_t i = 0; i < numOfTextToDisplay; ++i)
    {
        window.draw(texts.at(i));
    }
}

#include "text.hpp"

Text::Text()
{
    if(font.loadFromFile(R"(Fonts\StalinistOne-Regular.ttf)"))
    {
        std::transform(texts.begin(), texts.end(), texts.begin(), [this](sf::Text t){ t.setFont(font); return t; });
        std::transform(texts.begin(), texts.end(), texts.begin(), TextBuilder());
    }
}

void Text::update(int points, std::size_t length)
{
    texts[TextType::PointsText].setString("Points: " + std::to_string(points));
    texts[TextType::LengthText].setString("Length: " + std::to_string(length));
}

void Text::draw(sf::RenderWindow& window, bool isGameOver)
{
    if(!isGameOver)
    {
        for(std::size_t i = 0; i < texts.size() - 1; ++i)
        {
            window.draw(texts.at(i));
        }
    }
    else
        window.draw(texts.at(TextType::GameOverText));
}

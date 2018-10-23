#include "images.hpp"

Images::Images()
{
    if(!m_texture.loadFromFile("D:\\Moje programy\\snake_sfml\\images\\snake.png"))
    {
        //Error
    }

    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(510, 200);
}

void Images::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_sprite);
}

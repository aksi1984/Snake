#ifndef IMAGES_HPP
#define IMAGES_HPP

#include <SFML/Graphics.hpp>


class Images : public sf::Drawable
{
public:
    Images();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
};

#endif // IMAGES_HPP

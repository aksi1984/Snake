#include "object.hpp"
#include <iostream>

Object::Object()
{
    if(texture.loadFromFile(R"(D:\Moje programy\snake_sfml\sprites\snake head.png)"))
    {
        sprite.setTexture(texture);
    }
}

void Object::setColor(sf::Color color)
{
    sprite.setColor(color);
}

void Object::setPosition(float x, float y)
{
    sprite.setPosition(sprite.getPosition().x + x, sprite.getPosition().y + y);
}

void Object::setPosition(const sf::Vector2f& position)
{
    sprite.setPosition(position);
}

sf::Vector2f Object::getPosition() const
{
    return sprite.getPosition();
}

sf::FloatRect Object::getGlobalBounds() const
{
    return sprite.getGlobalBounds();
}

void Object::draw(sf::RenderTarget& window)
{
    window.draw(sprite);
}

////////////////////////////////////////////////

SnakeHead::SnakeHead() :
    velocityX(0),
    velocityY(20.f),
    timeLimit(0.25)
{
    Object::setColor(sf::Color(255,164,032));
    Object::setPosition(100.f, 100.f);
    prevPosition = Object::getPosition();
}

void SnakeHead::handleArrowKey(sf::Keyboard::Key key)
{
    float x = 0;
    float y = 0;

    switch(key)
    {
    case sf::Keyboard::Up:
        y = -20.f;
        direction = 1;
        break;
    case sf::Keyboard::Down:
        y = 20.f;
        direction = 2;
        break;
    case sf::Keyboard::Left:
        x = -20.f;
        direction = 3;
        break;
    case sf::Keyboard::Right:
        x = 20.f;
        direction = 4;
        break;
    default:
        break;
    }

    velocityX = x;
    velocityY = y;
}

void SnakeHead::move(sf::Clock& clock)
{
    sf::Time time = clock.getElapsedTime();

    if(time > sf::seconds(timeLimit))
    {
        prevPosition = Object::getPosition();
        Object::setPosition(velocityX, velocityY);
        clock.restart();
        changeOfPos = true;
    }
    else
        changeOfPos = false;
}

bool SnakeHead::outsideTheField()
{
    return ( Object::getPosition().x < 0 || Object::getPosition().x > ScreenRes::GameWidth - Object::getGlobalBounds().width ||
             Object::getPosition().y < 0 || Object::getPosition().y > ScreenRes::Heigh - Object::getGlobalBounds().height );
}

sf::Vector2f SnakeHead::getPrevPosition() const
{
    return prevPosition;
}

bool SnakeHead::itMoving() const
{
    return changeOfPos;
}

///////////////////////////////////////////////////

SnakeBody::SnakeBody()
{
    Object::setColor(sf::Color(203,040,033));
}

///////////////////////////////////////////////////

Fruit::Fruit()
{
    Object::setColor(sf::Color(030,89,69));
}

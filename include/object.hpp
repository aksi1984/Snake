#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "randfunc.hpp"
#include "myUtility.hpp"
#include <SFML/Graphics.hpp>

class Object
{
public:
    Object();

    void setPosition(float x, float y);
    void setPosition(const sf::Vector2f& position);
    sf::Vector2f getPosition() const;
    sf::FloatRect getGlobalBounds() const;
    void draw(sf::RenderTarget& window);

protected:
    void setColor(sf::Color color);

private:
    sf::Texture texture;
    sf::Sprite sprite;
};

////////////////////////////////////

class SnakeHead : public Object
{
public:
    SnakeHead();
    void handleArrowKey(sf::Keyboard::Key key);
    void move(sf::Clock& clock);
    sf::Vector2f getPrevPosition() const;
    bool itMoving() const;

private:
    void moveLimit();

    float velocityX;
    float velocityY;

    float timeLimit;
    std::size_t direction;
    sf::Vector2f prevPosition;

    bool changeOfPos;
};

////////////////////////////////////

class SnakeBody : public Object
{
public:
    SnakeBody();
};

////////////////////////////////////

class Fruit : public Object
{
public:
    Fruit();
};


#endif // OBJECT_HPP

#ifndef COLLISIONS_HPP
#define COLLISIONS_HPP

#include "object.hpp"

template<typename T>
bool isCollision(const SnakeHead& snakeHead, const T& otherObject)
{
    return ( snakeHead.getPosition() == otherObject.getPosition() );
}

#endif // COLLISIONS_HPP

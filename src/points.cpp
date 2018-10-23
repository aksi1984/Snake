#include "points.hpp"

Points::Points() :
    actualPoints(0) { }

void Points::addPoint()
{
    actualPoints++;
}

int Points::getPoints() const
{
    return actualPoints;
}

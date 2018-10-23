#ifndef RANDFUNC_HPP
#define RANDFUNC_HPP

#include "myUtility.hpp"
#include <SFML/Graphics.hpp>
#include <random>
#include <algorithm>

struct RandFunc
{
public:
    RandFunc();

    void createVecOfCoords(float bound);
    sf::Vector2f operator()();

private:
    std::vector<float> widths;
    std::vector<float> heighs;
};

#endif // RANDFUNC_HPP

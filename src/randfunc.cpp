#include "randfunc.hpp"


RandFunc::RandFunc() { }

void RandFunc::createVecOfCoords(float bound)
{
    std::size_t widthsVecSz = (ScreenRes::GameWidth - (bound * 2)) / bound;
    std::generate_n(std::back_inserter(widths), widthsVecSz, [bound]{ static float x = bound; return x += bound; } );

    std::size_t heighsVecSz = (ScreenRes::Heigh - (bound * 2)) / bound;
    std::generate_n(std::back_inserter(heighs), heighsVecSz, [bound]{ static float y = bound; return y += bound; } );
}

sf::Vector2f RandFunc::operator()()
{
    thread_local std::mt19937 gen{std::random_device{}()};
    std::size_t x = std::uniform_int_distribution<std::size_t>{0, widths.size() - 1}(gen);
    std::size_t y = std::uniform_int_distribution<std::size_t>{0, heighs.size() - 1}(gen);

    return sf::Vector2f(widths[x], heighs[y]);
}

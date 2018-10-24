#ifndef TEXTBASE_HPP
#define TEXTBASE_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>

class TextBase
{
public:
    TextBase(std::size_t textVecSz, const std::string& fileName);
    virtual ~TextBase();

    virtual void draw(sf::RenderWindow& window) = 0;

protected:
    sf::Font font;
    std::vector<sf::Text> textVec;
};

#endif // TEXTBASE_HPP

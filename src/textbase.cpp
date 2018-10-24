#include "textbase.hpp"

TextBase::TextBase(std::size_t textVecSz, const std::string& fileName) :
    textVec(textVecSz)
{
    if(font.loadFromFile(fileName))
    {
        std::transform(textVec.begin(), textVec.end(), textVec.begin(), [this](sf::Text t){ t.setFont(font); return t; });
    }
}

TextBase::~TextBase() { }

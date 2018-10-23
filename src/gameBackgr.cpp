#include "gameBackgr.hpp"
#include <iostream>

GameBackgr::GameBackgr() :
    texturesVec(3)
{
    fileNames =
    {
        R"(sprites\play backgr.png)",
        R"(sprites\game backgr.png)",
        R"(sprites\results backgr.png)"
    };

    createBackgr();
}

void GameBackgr::createBackgr()
{
    auto makeBackgr = [this](sf::Sprite sprite)
    {
        static std::size_t count = 0;

        if(texturesVec[count].loadFromFile(fileNames[count]))
        {
            sprite.setTexture(texturesVec[count]);
        }
        else
            std::runtime_error(fileNames[count] + " does not exist");

        count++;

        return sprite;
    };

    std::transform(sprites.begin(), sprites.end(), sprites.begin(), makeBackgr);

    sprites[2].setPosition(ScreenRes::GameWidth, 0);
}

void GameBackgr::draw(sf::RenderWindow& window)
{
    for(auto x : sprites) window.draw(x);
}

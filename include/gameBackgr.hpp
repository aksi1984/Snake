#ifndef GAMEBACKGR_HPP
#define GAMEBACKGR_HPP

#include "myUtility.hpp"
#include <SFML/Graphics.hpp>
#include <map>



class GameBackgr
{
public:
    GameBackgr();

    void draw(sf::RenderWindow& window);

private:
    void createBackgr();

    enum {FileNamesArraySz = 3};

    sf::Texture texture;
    std::vector<sf::Texture> texturesVec;
    std::array<sf::Sprite, FileNamesArraySz> sprites;
    std::array<std::string, FileNamesArraySz> fileNames;
};

#endif // GAMEBACKGR_HPP

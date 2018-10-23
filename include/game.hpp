#ifndef GAME_HPP
#define GAME_HPP

#include "myUtility.hpp"
#include "gameBackgr.hpp"
#include "text.hpp"
#include "sounds.hpp"
#include "points.hpp"
#include "object.hpp"
#include "collisions.hpp"
#include "deque"

class Game
{
public:
    Game();

    bool isGameOver() const;
    void run();

private:
    void processEvent();
    void objectsMove();
    void update();
    void playSounds();
    void render();

    sf::RenderWindow window;
    sf::Clock clock;

    GameBackgr backgrounds;
    Text text;
    Points points;
    Sound sound;

    SnakeHead snakeHead;
    SnakeBody snakeBodySegment;
    std::deque<SnakeBody> snakeBodyDeque;
    Fruit fruit;

    RandFunc randFunc;

    bool canPlaySound;
    bool gameOver;
};


#endif // GAME_HPP
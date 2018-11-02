#ifndef GAME_HPP
#define GAME_HPP

#include "myUtility.hpp"
#include "state.hpp"
#include "gamebackgr.hpp"
#include "gametext.hpp"
#include "sounds.hpp"
#include "points.hpp"
#include "object.hpp"
#include "collisions.hpp"
#include "deque"

class Game : public State
{
public:
    Game();

    void run(sf::RenderWindow& window);

protected:
    void reset();

private:
    void processEvent(sf::RenderWindow& window);
    void objectsMove();
    void updateObjects();
    void updateText();
    void playSounds();
    void render(sf::RenderWindow& window);

    sf::Clock clock;

    GameBackgr backgrounds;
    GameText gameText;
    Points points;
    Sound sound;

    SnakeHead snakeHead;
    SnakeBody snakeBodySegment;
    std::deque<SnakeBody> snakeBodyDeque;
    Fruit fruit;

    RandFunc randFunc;

    bool canPlaySound;
    bool gameOver;
    bool isGameBegin;
};


#endif // GAME_HPP

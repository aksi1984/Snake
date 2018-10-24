#include "game.hpp"
#include <iostream>


Game::Game() :
    window(sf::VideoMode(ScreenRes::Width, ScreenRes::Heigh), "Snake"),
    canPlaySound(false),
    gameOver(false)
{
    randFunc.createVecOfCoords(fruit.getGlobalBounds().width);
    fruit.setPosition(randFunc());
}

void Game::run()
{
    clock.restart();

    while(window.isOpen())
    {
        processEvent();
        objectsMove();
        updateObjects();
        updateText();
        playSounds();
        render();
    }
}

bool Game::isGameOver() const
{
    return gameOver;
}

void Game::processEvent()
{
    sf::Event event;

    while(window.pollEvent(event))
    {
        switch(event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
            snakeHead.handleArrowKey(event.key.code);
            break;
        default:
            break;
        }
    }

    if(gameOver)
    {
        sf::sleep(sf::Time(sf::seconds(3.f)));
        window.close();
    }
}

void Game::objectsMove()
{

    if(snakeHead.itMoving())
    {
        snakeBodySegment.setPosition(snakeHead.getPrevPosition());
        snakeBodyDeque.push_front(snakeBodySegment);
        snakeBodyDeque.pop_back();
    }

    snakeHead.move(clock);
}

void Game::updateObjects()
{
    if(isCollision(snakeHead, fruit))
    {
        if(snakeHead.itMoving())
        {
            snakeBodySegment.setPosition(snakeHead.getPrevPosition());
            snakeBodyDeque.push_front(snakeBodySegment);
            fruit.setPosition(randFunc());
            points.addPoint();

        }

        canPlaySound = true;
    }
    else
        canPlaySound = false;

    for(auto x : snakeBodyDeque)
    {
        gameOver = isCollision(snakeHead, x);

        if(gameOver)
            break;
    }
}

void Game::updateText()
{
    gameText.update(points.getPoints(), snakeBodyDeque.size());
    gameText.setNumTextToDisplay(gameOver);
}

void Game::playSounds()
{
    ( canPlaySound ? sound.play() : (void)0 );
}

void Game::render()
{
    window.clear(sf::Color::White);
    backgrounds.draw(window);
    gameText.draw(window);
    snakeHead.draw(window);
    for(auto x : snakeBodyDeque) x.draw(window);
    fruit.draw(window);
    window.display();
}

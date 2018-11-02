#include "game.hpp"
#include <iostream>


Game::Game() :
    canPlaySound(false),
    gameOver(false),
    isGameBegin(true)
{
    randFunc.createVecOfCoords(fruit.getGlobalBounds().width);
    fruit.setPosition(randFunc());
}

void Game::reset()
{
    snakeBodyDeque.clear();
    points.resetPoints();
    fruit.setPosition(randFunc());
    snakeHead.setPosition(randFunc());
    gameOver = false;
}

void Game::run(sf::RenderWindow& window)
{
    if(isGameBegin)
    {
        clock.restart();
        isGameBegin = false;
    }

    processEvent(window);
    objectsMove();
    updateObjects();
    updateText();
    playSounds();
    render(window);
}

void Game::processEvent(sf::RenderWindow& window)
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
        State::setState(GameStates::StateMenu);
        reset();
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

    gameOver = snakeHead.outsideTheField();

    for(auto x : snakeBodyDeque)
    {
        gameOver = isCollision(snakeHead, x);
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

void Game::render(sf::RenderWindow& window)
{
    backgrounds.draw(window);
    gameText.draw(window);
    snakeHead.draw(window);
    for(auto x : snakeBodyDeque) x.draw(window);
    fruit.draw(window);
}

#include "statemanager.hpp"

StateManager::StateManager() :
    window(sf::VideoMode(Width, Heigh), "Snake"),
    endGame(false)
{
    statesArray =
    {
        std::unique_ptr<State>(new Menu),
        std::unique_ptr<State>(new Game)
    };

    currentStateNum = GameStates::StateMenu;
}

void StateManager::run()
{
    while(window.isOpen())
    {
        selectState();
        display();
    }
}

void StateManager::selectState()
{
    if(statesArray.at(currentStateNum)->getState() == GameStates::StateMenu)
    {
        currentStateNum = GameStates::StateMenu;
        statesArray.at(currentStateNum)->setState(GameStates::StateMenu);
    }
    else if(statesArray.at(currentStateNum)->getState() == GameStates::StateGame)
    {
        currentStateNum = GameStates::StateGame;
        statesArray.at(currentStateNum)->setState(GameStates::StateGame);
    }
}

void StateManager::display()
{
    window.clear(sf::Color::White);
    statesArray.at(currentStateNum)->run(window);
    window.display();
}

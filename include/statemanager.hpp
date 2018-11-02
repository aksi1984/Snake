#ifndef STATEMANAGER_HPP
#define STATEMANAGER_HPP

#include "myUtility.hpp"
#include "menu.hpp"
#include "game.hpp"
#include <SFML/Graphics.hpp>
#include <array>
#include <memory>


class StateManager
{
public:
    StateManager();

    void run();

private:
    void selectState();
    void display();

    enum { StatesArraySz = 2 };
    std::array<std::unique_ptr<State>, StatesArraySz> statesArray;

    sf::RenderWindow window;

    std::size_t currentStateNum;

    bool endGame;
};


#endif // STATEMANAGER_HPP

#ifndef STATE_HPP
#define STATE_HPP

#include "myUtility.hpp"
#include <SFML/Graphics.hpp>
#include <memory>

class State
{
public:
    State();

    void setState(GameStates state);
    virtual void run(sf::RenderWindow& window) = 0;
    GameStates getState() const;

private:
    GameStates gameStates;
};

#endif // STATE_HPP

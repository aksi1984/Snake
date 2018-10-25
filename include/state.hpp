#ifndef STATE_HPP
#define STATE_HPP

#include "myUtility.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class State
{
public:
    State();
    virtual ~State();

    virtual void run(sf::RenderWindow& window) = 0;
    GameState getState() const;

protected:
    void setState(GameState gSstate);

private:
    GameState gameState;
};

/////////////////////////////////

class Client
{
public:
    Client();

private:
    std::vector<State> state;

    sf::RenderWindow window;
};

#endif // STATE_HPP

#include "state.hpp"

State::State() { }

State::~State() { }

void State::setState(GameState gState)
{
    gameState = gState;
}

GameState State::getState() const
{
    return gameState;
}


#include "state.hpp"


State::State() {}

void State::setState(GameStates state)
{
    gameStates = state;
}

GameStates State::getState() const
{
    return gameStates;
}

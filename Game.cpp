#include "Game.hpp"

Game::Game(){}
Game::~Game() {}

void    Game::gameplay()
{
    IncGraphics inc;

    while(!_init.getGameOver())
    {
        inc.DrawMap(_border);
        inc.Draw(_fruits, _stat, _init);
        // input
        // logic
    }
    
}
#include "Game.hpp"

Game::Game(){}
Game::~Game() {}

void    Game::gameplay()
{
    IncGraphics inc;

    while(!_init.getGameOver())
    {
        inc.DrawMap(_init.getHeight(), _init.getWidth());
        //draw
        // input
        // logic
    }
    
}
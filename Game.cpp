#include "Game.hpp"

Game::Game(){}
Game::~Game() {}

void    Game::gameplay()
{
    IncGraphics inc;
    Direction   dr = stop;
    clock_t t1;
    clock_t t2;

    t2 = 0;
    while(!_init.getGameOver())
    {
        inc.DrawMap(_border);
        inc.Draw(_snake, _fruits, _stat, _init);

        t1 = clock() / (CLOCKS_PER_SEC / 30);
        if (t1 > t2)
        {
            dr = inc.CheckEvent(dr);
            _logic.logic(_fruits, _snake, _stat, dr);
            // TODO:input
            // TODO:logic <- input;
            t2 = clock() / (CLOCKS_PER_SEC / 30);
        }
    }
}

Game &Game::operator=(Game const &rhs)
{
    if (this != &rhs)
    {
        _init = rhs._init;
        _border = rhs._border;
        _stat = rhs._stat;
        _fruits = rhs._fruits;
        _snake = rhs._snake;
    }
    return *this;
}

Game::Game(Game const &src) { *this = src; }
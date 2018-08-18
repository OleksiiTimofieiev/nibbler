#include "Game.hpp"

Game::Game(){}
Game::~Game() {}

void    Game::gameplay()
{
    IncGraphics inc;

    while(!_init.getGameOver())
    {
        inc.DrawMap(_border);
        inc.Draw(_snake, _fruits, _stat, _init);
        // TODO:input
        // TODO:logic <- input;
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
#include "Init.hpp"

Init::~Init(){};
Init::Init() : _gameOver(false), _width(20), _height(20) {};

Init &Init::operator=(Init const &rhs)
{
    if (this != &rhs)
    {
        _gameOver = rhs._gameOver;
        _width = rhs._width;
        _height = rhs._height;
    }
    return *this;
}

Init::Init(Init const &src)
{
    *this = src;
}
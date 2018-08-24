#include "../includes/Init.hpp"

Init::~Init(){};
Init::Init() {};
Init::Init(int size) : _gameOver(false), _width(size), _height(size){};

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

Init::Init(Init const &src) { *this = src; }

bool Init::getGameOver() {return _gameOver;}
int Init::getWidth() { return _width; }
int Init::getHeight() { return _height; }
void Init::setGameStatus() { _gameOver = true;};

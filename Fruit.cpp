#include "Fruit.hpp"

Fruit::~Fruit(){};
Fruit::Fruit() : _width(20), _height(20){};

Fruit &Fruit::operator=(Fruit const &rhs)
{
    if (this != &rhs)
    {
        _width = rhs._width;
        _height = rhs._height;
    }
    return *this;
}

Fruit::Fruit(Fruit const &src)
{
    *this = src;
}

int Fruit::getWidth() { return _width; }
int Fruit::getHeight() { return _height; }
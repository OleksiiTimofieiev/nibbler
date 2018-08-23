#include "Border.hpp"

Border::~Border(){};
Border::Border() : _width(50), _height(50){};

Border &Border::operator=(Border const &rhs)
{
    if (this != &rhs)
    {
        _width = rhs._width;
        _height = rhs._height;
    }
    return *this;
}

Border::Border(Border const &src)
{
    *this = src;
}

int Border::getWidth() { return _width; }
int Border::getHeight() { return _height; }
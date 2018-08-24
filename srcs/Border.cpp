#include "../includes/Border.hpp"

Border::Border(){}
Border::~Border(){}
Border::Border(int size)
{
    _width = size;
    _height = size;
} 

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
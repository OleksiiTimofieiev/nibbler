#include "Snake.hpp"

#include <iostream>

Snake::Snake(){}
Snake::~Snake(){}

Snake::Snake(int x, int y)
{
    _head_coords.first = x;
    _head_coords.second = y;
    _dir = stop;
    _tail_len = 0;

    for (int i = 1; i <= 3; i++)
        _tail.push_back(std::make_pair(x, y + i));
}

Snake &Snake::operator=(Snake const &rhs)
{
    if (this != &rhs)
    {
        _head_coords = rhs._head_coords;
        _tail = rhs._tail;
        _dir = rhs._dir;
    }
    return *this;
}

Snake::Snake(Snake const &src) {*this = src;}
std::pair<int, int> Snake::getHeadCoords() { return _head_coords; }
std::vector<std::pair<int, int> > Snake::getTailCoords() { return _tail; }
Direction Snake::getDir() {return _dir;}
void      Snake::setDir(Direction dir) { _dir = dir;};

void                 Snake::setHeadCoords(int x, int y)
{ 
    _head_coords.first = x;
    _head_coords.second = y;
}

void                 Snake::setTailLen() { _tail_len++;}
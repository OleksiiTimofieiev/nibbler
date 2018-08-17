#include "Snake.hpp"

#include <iostream>

Snake::Snake(){}
Snake::~Snake() {}

Snake &Snake::operator=(Snake const &rhs)
{
    if (this != &rhs)
    {
        _head_coords = rhs._head_coords;
        _tail = rhs._tail;
    }
    return *this;
}

Snake::Snake(Snake const &src)
{
    *this = src;
}

Snake::Snake(int x, int y)
{
    _head_coords.first = x;
    _head_coords.second = y;

    for (int i = 1; i <= 3; i++)
        _tail.push_back(std::make_pair(x, y + i));
}

std::pair<int, int> Snake::getHeadCoords() { return _head_coords; }
std::vector<std::pair<int, int> > Snake::getTailCoords() { return _tail; }
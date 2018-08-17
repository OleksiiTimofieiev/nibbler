#include "Snake.hpp"

#include <iostream>

Snake::Snake(){}
Snake::~Snake() {}

Snake::Snake(int x, int y)
{
    _head_coords.first = x;
    _head_coords.second = y;

    for (int i = 1; i <= 3; i++)
        _tail.push_back(std::make_pair(x, y + i));
}
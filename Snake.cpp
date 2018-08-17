#include "Snake.hpp"

Snake::Snake(){}
Snake::~Snake() {}

Snake::Snake(int x, int y)
{
    _head_coords.first = x;
    _head_coords.second = y;
}
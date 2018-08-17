#include "Snake.hpp"

#include <iostream>

Snake::Snake(){}
Snake::~Snake() {}

// std::vector<std::pair<int, int>> cor;

// cor.push_back(std::make_pair(1, 1));
// cor.push_back(std::make_pair(2, 2));
// cor.push_back(std::make_pair(3, 3));

// for (size_t i = 0; i < cor.size() - 1; i++)
// {
//     std::swap(cor[i], cor[i + 1]);
// }

// for (size_t i = 0; i < cor.size(); i++)
// {
//     std::cout << cor[i].first << ", " << cor[i].second << std::endl;
// }

Snake::Snake(int x, int y)
{
    _head_coords.first = x;
    _head_coords.second = y;
    _tail.push_back(std::make_pair(x, y + 1));
    _tail.push_back(std::make_pair(x, y + 2));
    _tail.push_back(std::make_pair(x, y + 3));

    for (size_t i = 0; i < _tail.size(); i++)
    {
        std::cout << _tail[i].first << ", " << _tail[i].second << std::endl;
    }
}
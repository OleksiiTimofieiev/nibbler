#include "../includes/Snake.hpp"

#include <iostream>

Snake::Snake(){}
Snake::~Snake(){}

Snake::Snake(int x, int y)
{
    _head_coords.first = x;
    _head_coords.second = y;
    
    _dir = stop;
    _tail_len = 3;

    for (int i = 0; i < 3; i++)
        _tail[i] = std::make_pair(x, ++y);
    for (int i = 0, distance = 2; i < 5; i++, distance += 6)
        _obstacles.push_back(std::make_pair(distance, distance));
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

void                 Snake::setTailLen() { _tail_len++; }
int                  Snake::getTailLen() { return _tail_len; }
void                 Snake::setTail(std::vector<std::pair<int, int> > tail) { _tail = tail; };

std::vector<std::pair<int, int> > Snake::getPrevTailCoords() { return _prev_tail; }
void Snake::setPrevTail(std::vector<std::pair<int, int>> prev_tail) { _prev_tail = prev_tail; };

void Snake::setPrevHead(std::pair<int, int> _prev_head) { _prev_head_coords = _prev_head; };
std::pair<int, int> Snake::getPrevHeadCoords() { return _prev_head_coords;}

Direction Snake::getPrevDir() { return _prev_dir; }
void Snake::setPrevDir(Direction dir) { _prev_dir = dir; }

std::vector<std::pair<int, int> > Snake::getObstacleCoords() { return _obstacles; }
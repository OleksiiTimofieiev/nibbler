#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <vector>

class Snake
{
    std::pair<int, int> _head_coords;
    
    std::vector<std::pair<int, int> > tail;
};

#endif
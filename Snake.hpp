#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <vector>

class Snake
{
    std::pair<int, int> _head_coords;
    
    std::vector<std::pair<int, int> > _tail;

    public:
        Snake();
        ~Snake();
        Snake(int x, int y);
        std::pair<int, int>               getHeadCoords();
        std::vector<std::pair<int, int> > getTailCoords();
};

#endif
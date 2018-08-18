#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <vector>

#include "Init.hpp"

enum Direction
{
    stop = 0,
    left,
    right,
    up,
    down
};

class Snake
{
    std::pair<int, int> _head_coords;
    std::vector<std::pair<int, int> > _tail{(WIDTH * HEIGHT) - 1};
    int _tail_len;
    Direction _dir;

    public:
        Snake();
        ~Snake();
        Snake &operator=(Snake const &rhs);
        Snake(Snake const &src);
        Snake(int x, int y);
        std::pair<int, int>               getHeadCoords();
        std::vector<std::pair<int, int> > getTailCoords();
        Direction                         getDir();
        void                              setHeadCoords(int x, int y);
        void                              setDir(Direction dir);
        void                              setTailLen();
        void                              setTail();
        int                               getTailLen();
        void                               setTail(std::vector<std::pair<int, int> > tail);
};

#endif
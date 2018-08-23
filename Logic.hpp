#ifndef LOGIC_HPP
#define LOGIC_HPP

#include "Snake.hpp"
#include "Fruit.hpp"
#include "Score.hpp"
#include "Init.hpp"

#define FPS_CHANGE 2

class Logic
{
    public:
        void    setDir(Direction dir,  Snake & snake);
        void    setHead(Snake & snake);
        void    checkFruit(Fruit & fruit, Snake & snake, Score & score, int & fps);
        void    logic(Init & init, Fruit & fruit, Snake & snake, Score & score, Direction dir, int & fps);
        void    setTail(Snake & snake);
        void    checkCollision(Snake & snake, Init & init);
};

#endif
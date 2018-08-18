#ifndef LOGIC_HPP
#define LOGIC_HPP

#include "Snake.hpp"
#include "Fruit.hpp"
#include "Score.hpp"
#include "Init.hpp"




class Logic
{
    public:
        void    setDir(Direction dir,  Snake & snake);
        void    setHead(Snake & snake);
        void    checkFruit(Fruit & fruit, Snake & snake, Score & score);
        

};



#endif
#ifndef LOGIC_HPP
# define LOGIC_HPP

#include "IMusic.hpp"
#include "Snake.hpp"
#include "Fruit.hpp"
#include "Score.hpp"
#include "Init.hpp"

#define FPS_CHANGE 2

class Logic
{
    private:
        int     _size;
    public:
        Logic();
        ~Logic();
        Logic(int size);
        Logic &operator=(Logic const &rhs);
        Logic(Logic const &src);
        
        void    setDir(Direction dir,  Snake & snake);
        void    setHead(Snake & snake);
        void    checkFruit(Fruit &fruit, Snake &snake, Score &score, int &fps, IMusic *music);
        void    logic(Init & init, Fruit & fruit, Snake & snake, Score & score, Direction dir, int & fps, IMusic *music);
        void    setTail(Snake & snake);
        void    checkCollision(Snake &snake, Init &init, IMusic *music);
};

#endif
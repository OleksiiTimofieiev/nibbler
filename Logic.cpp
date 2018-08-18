#include "Logic.hpp"

//TODO: logic main;

void    Logic::setDir(Direction dir,  Snake & snake)
{ 
    snake.setDir(dir); 
}

void Logic::setHead(Snake & snake)
{
    if ( snake.getDir() == left )
        snake.setHeadCoords(snake.getHeadCoords().first - 1, snake.getHeadCoords().second);
    else if ( snake.getDir() == right)
        snake.setHeadCoords(snake.getHeadCoords().first + 1, snake.getHeadCoords().second);
    else if ( snake.getDir() == up)
        snake.setHeadCoords(snake.getHeadCoords().first, snake.getHeadCoords().second - 1);
    else if ( snake.getDir()  == down)
       snake.setHeadCoords(snake.getHeadCoords().first, snake.getHeadCoords().second + 1);
}

void    Logic::checkFruit(Fruit & fruit, Snake & snake, Score & score)
{
    if (fruit.getCoords() == snake.getHeadCoords())
        fruit.setCoords(rand() % 125, rand() % 40);
    score.setScore();
}

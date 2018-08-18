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
        fruit.setCoords(rand() % WIDTH, rand() % HEIGHT);
    score.setScore();
}

void    Logic::logic(Fruit & fruit, Snake & snake, Score & score, Direction dir)
{
    setDir(dir, snake);
    setHead(snake);
    checkFruit(fruit, snake, score);
}

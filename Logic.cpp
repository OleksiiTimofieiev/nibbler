#include "Logic.hpp"

void    Logic::setDir(Direction dir,  Snake & snake) { snake.setDir(dir); }

void    Logic::setTail(Snake & snake)
{
    std::pair<int, int> prev{snake.getTailCoords()[0].first, snake.getTailCoords()[0].second};
    std::pair<int, int> prev2{0, 0};


    std::vector<std::pair<int, int> > _tail = snake.getTailCoords();

    snake.setPrevTail(_tail);

    _tail[0].first = snake.getHeadCoords().first;
    _tail[0].second = snake.getHeadCoords().second;

    for (int i = 1; i < snake.getTailLen(); i++)
    {
        prev2 = _tail[i];
        _tail[i] = prev;
        prev = prev2;
    }
    snake.setTail(_tail);
}

void Logic::setHead(Snake & snake)
{
    snake.setPrevHead(snake.getPrevHeadCoords());
    snake.setPrevDir(snake.getPrevDir());

    if ( snake.getDir() == left )
        snake.setHeadCoords(snake.getHeadCoords().first - 1, snake.getHeadCoords().second);
    else if ( snake.getDir() == right)
        snake.setHeadCoords(snake.getHeadCoords().first + 1, snake.getHeadCoords().second);
    else if ( snake.getDir() == up)
        snake.setHeadCoords(snake.getHeadCoords().first, snake.getHeadCoords().second - 1);
    else if ( snake.getDir()  == down)
       snake.setHeadCoords(snake.getHeadCoords().first, snake.getHeadCoords().second + 1);
}

void    Logic::checkFruit(Fruit & fruit, Snake & snake, Score & score, int & fps)
{
    if (fruit.getCoords() == snake.getHeadCoords())
    {
        fruit.setCoords(rand() % WIDTH, rand() % HEIGHT);
        score.setScore();
        snake.setTailLen();
        setTail(snake); //TODO: show ignat;
        fps += FPS_CHANGE;
    }
}

void    Logic::checkCollision(Snake &snake, Init &init)
{
    if (snake.getHeadCoords().first > init.getWidth()   || snake.getHeadCoords().first < 0 ||
        snake.getHeadCoords().second > init.getHeight() || snake.getHeadCoords().second < 0)
    {
        std::cout << "Border type collision." << std::endl;
        init.setGameStatus();
    }

    for (int i = 0; i < snake.getTailLen(); i++)
        if (snake.getTailCoords()[i] == snake.getHeadCoords())
        {
            std::cout << "Tail type collision." << std::endl;
            init.setGameStatus();
        }

    std::vector<std::pair<int ,int> > check = snake.getObstacleCoords();

    for (int i = 0; i < 5; i++)
        if (snake.getHeadCoords().first == check[i].first && snake.getHeadCoords().second == check[i].second)
        {
            std::cout << "Obstacle type collision." << std::endl;
            init.setGameStatus();
        }
}

void    Logic::logic(Init & init, Fruit & fruit, Snake & snake, Score & score, Direction dir, int & fps) // TODO: show fps change to Ignat;
{
    if (dir == stop_the_game) // TODO: show Igmat
    {
        std::cout << "Fatal error" << std::endl;
        exit(0);
    }
    setDir(dir, snake);
    setTail(snake);
    setHead(snake);
    checkCollision(snake, init);
    checkFruit(fruit, snake, score, fps);
}

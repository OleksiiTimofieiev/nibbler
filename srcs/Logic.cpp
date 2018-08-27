#include "../includes/Logic.hpp"

Logic::Logic() {};
Logic::~Logic() {}

Logic &Logic::operator=(Logic const &rhs)
{
    if (this != &rhs)
    {
        _size = rhs._size;
    }
    return *this;
}

Logic::Logic(Logic const &src) { *this = src; }

Logic::Logic(int size) : _size(size) {}
void    Logic::setDir(Direction dir,  Snake & snake) {

    if (dir == left && snake.getDir() != right)
        snake.setDir(dir);
    else if (dir == right && snake.getDir() != left)
        snake.setDir(dir);
    else if (dir == down && snake.getDir() != up)
        snake.setDir(dir);
    else if (dir == up && snake.getDir() != down)
        snake.setDir(dir);
}

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

void Logic::checkFruit(Fruit &fruit, Snake &snake, Score &score, int &fps, IMusic *music)
{
    if (fruit.getCoords() == snake.getHeadCoords())
    {
        music->playEating();
        srand(clock());
        fruit.setCoords(rand() % _size, rand() % _size);
        score.setScore();
        snake.setTailLen();
        setTail(snake);
        fps += FPS_CHANGE;
    }
}

void Logic::checkCollision(Snake &snake, Init &init, IMusic *music)
{
    if (snake.getHeadCoords().second > init.getHeight())
        snake.setHeadCoords(snake.getHeadCoords().first, 0);
    else if (snake.getHeadCoords().second == -1)
        snake.setHeadCoords(snake.getHeadCoords().first, init.getHeight());
    else if (snake.getHeadCoords().first > init.getWidth())
        snake.setHeadCoords(0, snake.getHeadCoords().second);
    else if (snake.getHeadCoords().first == -1)
        snake.setHeadCoords(init.getWidth(), snake.getHeadCoords().second);

    for (int i = 0; i < snake.getTailLen(); i++)
        if (snake.getTailCoords()[i] == snake.getHeadCoords())
        {
            music->playCollision();
            std::cout << "Tail type collision." << std::endl;
            init.setGameStatus();
        }

    std::vector<std::pair<int ,int> > check = snake.getObstacleCoords();

    for (int i = 0; i < 5; i++)
        if (snake.getHeadCoords().first == check[i].first && snake.getHeadCoords().second == check[i].second)
        {
            music->playCollision();
            std::cout << "Obstacle type collision." << std::endl;
            init.setGameStatus();
        }
}

void Logic::logic(Init &init, Fruit &fruit, Snake &snake, Score &score, Direction dir, int &fps, IMusic *music)
{
    if (dir == stop_the_game)
    {
        std::cout << "Game was stopped." << std::endl;
        init.setGameStatus();
    }
    setDir(dir, snake);
    setTail(snake);
    setHead(snake);
    checkCollision(snake, init, music);
    checkFruit(fruit, snake, score, fps, music);
}

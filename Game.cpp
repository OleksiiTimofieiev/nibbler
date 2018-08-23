#include "Game.hpp"

Game::Game(){}
Game::Game(int size) : _size(size) {}

Game::~Game() {}

void    Game::gameplay()
{
    Direction   dr = stop;
    IGraphics *inc = nullptr;

    libSelect(&inc, dr);

    clock_t t1;
    clock_t t2;

    t2 = 0;
    inc->DrawMap(_border);
    while(!_init.getGameOver())
    {
        t1 = clock() / (CLOCKS_PER_SEC / _fps);
        if (t1 > t2)
        {
            dr = inc->CheckEvent(dr);
            if (dr == change_the_lib)
                libSelect(&inc, dr);
            else if (dr != stop)
                _logic.logic(_init, _fruits, _snake, _stat, dr, _fps);
            inc->Draw(_snake, _fruits, _stat, _init);
            t2 = clock() / (CLOCKS_PER_SEC / _fps);
        }
    }
}

Game &Game::operator=(Game const &rhs)
{
    if (this != &rhs)
    {
        _init = rhs._init;
        _border = rhs._border;
        _stat = rhs._stat;
        _fruits = rhs._fruits;
        _snake = rhs._snake;
        _size = rhs._size;
    }
    return *this;
}

Game::Game(Game const &src) { *this = src; }

void Game::libSelect(IGraphics ** var, Direction & dir) // add direction;
{
    //TODO: size of the map;

    int lib;
    
    if (*var != nullptr)
    {
        delete (*var);
        *var = nullptr;
    }

    std::cout << "Please, choose the library" << std::endl;

    std::cout << "sdl -> 1" << std::endl;
    std::cout << "ncurses -> 2" << std::endl;
    std::cout << "sfml -> 3" << std::endl;

    std::cin >> lib;

    if (lib == 1)
        *var = new IGraphicsSDL();
    else if (lib == 2)
        *var = new IncGraphics();
    else if (lib == 3)
        *var = new SFMLGraphics();
    
    dir = stop;
}

int Game::input_check()
{
    int size = 0;
    bool checker = true;

    std::cout << "Please, enter the size of the board. Limit: 35 - 75 units of measurement" << std::endl;

    while (checker)
    {
        std::cin >> size;

        if (size >= 35 && size <= 75)
            checker = false;
        else
            std::cout << "Wrong input, Please, enter the size of the board. Limit: 35 - 75 units of measurement" << std::endl;
    }
    return (size);
}
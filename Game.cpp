#include "Game.hpp"

Game::Game(){}
Game::~Game() {}

void    Game::gameplay()
{
    int lib;
    std::cout << "Please, choose the library" << std::endl; // TODO: add some kind of usage;
    std::cin >> lib;

    IGraphics *inc = nullptr;


    // TODO: while loop till the correct input;
    // TODO: get a cool func;

    if ( lib == 1)
        inc = new IGraphicsSDL();
    else if ( lib == 2)
        inc = new IncGraphics();
    else if ( lib == 3 )
        inc = new SFMLGraphics();

    Direction   dr = stop;

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
            {
                delete inc;
                std::cout << "Please, choose the library" << std::endl;
                 // TODO: add some kind of usage;
                std::cin >> lib;

                    if ( lib == 1)
                        inc = new IGraphicsSDL();
                    else if ( lib == 2)
                        inc = new IncGraphics();
                    else if ( lib == 3 )
                        inc = new SFMLGraphics();
                        dr = stop;
                continue;
            }
            if (dr != stop)
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
    }
    return *this;
}

Game::Game(Game const &src) { *this = src; }
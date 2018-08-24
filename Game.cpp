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
            {
                libSelect(&inc, dr);
                inc->DrawMap(_border);
            }
            else if (dr != stop)
                _logic.logic(_init, _fruits, _snake, _stat, dr, _fps);
            inc->Draw(_snake, _fruits, _stat, _init);
            t2 = clock() / (CLOCKS_PER_SEC / _fps);
        }
    }
    if (inc != nullptr)
        delete (inc);
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
    int lib;
    
    if (*var != nullptr)
        delete(*var);

    std::cout << "Please, choose the library" << std::endl;

    std::cout << "sdl -> 1" << std::endl;
    std::cout << "ncurses -> 2" << std::endl;
    std::cout << "sfml -> 3" << std::endl;

    lib = lib_check();

    if (lib == 1)
        *var = new IGraphicsSDL();
    else if (lib == 2)
        *var = new IncGraphics();
    else if (lib == 3)
        *var = new SFMLGraphics(_init.getHeight(), _init.getWidth());
    
    dir = stop;
}

int Game::map_size_check()
{
    const std::regex check_input("^(\\d+)$");
    std::smatch result;

    std::string size;
    bool checker = true;
    int int_size;

    OUTPUT_GREEN("Please, enter the size of the board. Limit: 35 - 75 points of measurement");

    while (checker)
    {
        getline(std::cin, size);

        if ( std::regex_match(size, result, check_input) )
        {
            try
            {
                int_size = std::stoi(size);
            }
            catch (const std::exception & ex)
            {
                std::cout << "Simon says : " << ex.what() << std::endl;
            }

            if (int_size >= 35 && int_size <= 75)
                checker = false;
            else
                OUTPUT_RED("Simon says : Wrong input, Please, enter the size of the board. Limit: 35 - 75 points of measurement");
        }
        else
            OUTPUT_RED("Simon says : Wrong input, Please, enter the size of the board. Limit: 35 - 75 points of measurement");
    }
    return (int_size);
}

int Game::lib_check()
{
    std::cin.clear();
    const std::regex check_input("^(\\d+)$");
    std::smatch result;

    std::string size = "";
    bool checker = true;
    int choice;

    OUTPUT_GREEN("Please, enter the lib choice.");

    while (checker)
    {
        getline(std::cin, size);

        if (std::regex_match(size, result, check_input))
        {
            try
            {
                choice = std::stoi(size);
            }
            catch (const std::exception &ex)
            {
                std::cout << "Simon says : " << ex.what() << std::endl;
            }

            if (choice >= 1 && choice <= 3)
                checker = false;
            else
                OUTPUT_RED("Simon says : Wrong input, Please, enter the correct lib choice: 1 - 3");
        }
        else
            OUTPUT_RED("Simon says : Wrong input, Please, enter the correct lib choice: 1 - 3");
    }
    return (choice);
}
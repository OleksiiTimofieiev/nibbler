#include "../includes/Game.hpp"

Game::Game(){}
Game::Game(int size) : _size(size) {}

Game::~Game() {}

void    Game::gameplay()
{
    Direction   dr;
    clock_t t1;
    clock_t t2;

    t2 = 0;
    GetMusic();
    LibSelect(dr);
    _lib->DrawMap(_border);
    while(!_init.getGameOver())
    {
        t1 = clock() / (CLOCKS_PER_SEC / _fps);

        if (t1 > t2)
        {
            dr = _lib->CheckEvent(dr);

            if (dr == change_the_lib)
            {
                LibSelect(dr);
                _lib->DrawMap(_border);
            }
            else if (dr != stop)
                _logic.logic(_init, _fruits, _snake, _stat, dr, _fps, _music);

            _lib->Draw(_snake, _fruits, _stat, _init);
        t2 = clock() / (CLOCKS_PER_SEC / _fps);
        }
    }
    if (_lib != nullptr)
        delete (_lib);
   _stat.show();
    
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
        _fps = rhs._fps;
        _lib = rhs._lib;
        _dl = rhs._dl;
        _logic = rhs._logic;
    }
    return *this;
}
void Game::GetMusic(void)
{
    IMusic *(*create)() = nullptr;

    this->_dl_musoc = dlopen("./music_lib/music_lib.so", RTLD_LAZY | RTLD_LOCAL);

    if (this->_dl_musoc == nullptr)
        std::cerr << "open_lib: dlopen : " << dlerror() << std::endl;
    else if ((create = reinterpret_cast<IMusic *(*)()>(dlsym(this->_dl_musoc, "PlayMusic"))) == nullptr)
        std::cerr << "open_lib: dlsym : " << dlerror() << std::endl;

    this->_music = create();
}

Game::Game(Game const &src) { *this = src; }

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
    const std::regex check_input("^(\\d+)$");
    std::smatch result;

    std::string size;
    bool checker = true;
    int choice = 0;

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

void			Game::LibSelect(Direction & dir)
{
    int check = 0;
	IGraphics	*(*create)() = nullptr;

    if (_lib != nullptr)
        delete(_lib);

    std::cout << "Please, choose the library" << std::endl;

    std::cout << "sdl -> 1" << std::endl;
    std::cout << "ncurses -> 2" << std::endl;
    std::cout << "sfml -> 3" << std::endl;

    check = lib_check();
    
    if (check == 1)
        this->_dl = dlopen("./sdl_lib/sdl_lib.so", RTLD_LAZY | RTLD_LOCAL);
    else if (check == 2)
		this->_dl = dlopen("./ncurses_lib/ncurses_lib.so", RTLD_LAZY | RTLD_LOCAL);
	else if (check == 3)
		this->_dl = dlopen("./sfml_lib/sfml_lib.so", RTLD_LAZY | RTLD_LOCAL);

	if (this->_dl == nullptr)
		std::cerr << "open_lib: dlopen : "<< dlerror() << std::endl;
	else if (( create = reinterpret_cast<IGraphics* (*)()>(dlsym(this->_dl, "NewDisplay")) ) == nullptr)
        std::cerr << "open_lib: dlsym : " << dlerror() << std::endl;
        
	this->_lib = create();

    dir = stop;
}
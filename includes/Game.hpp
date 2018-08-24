#ifndef GAME_HPP
# define GAME_HPP

#include "Init.hpp"
#include "Border.hpp"
#include "Score.hpp"
#include "Fruit.hpp"
#include "Snake.hpp"

#include "IGraphics.hpp"

#include "Logic.hpp"
#include <ctime>
#include <sys/time.h>
#include <regex>
#include <iostream> // TODO:user trouble;

#include <dlfcn.h>


#define OUTPUT_RED(x) std::cout << "\033[1;31m" << (x) << "\x1B[0m" << std::endl;
#define OUTPUT_GREEN(x) std::cout << "\033[1;32m" << (x) << "\x1B[0m" << std::endl;

// TODO: 1. comp form in every class which has variables;
// TODO: 2. think about sounds;
// TODO: 3. randomness limits for the fruit;
// TODO: 4. constructor of SFML;

// TODO: 5. replace all of the bad names;

class Game
{
    private:
        int     _size = 0;
        Init    _init{_size};
        Border  _border{_size};
        Score   _stat; // TODO:output in the end of the game;
        Fruit   _fruits{_init.getWidth(), _init.getHeight()};
        Snake   _snake{_init.getWidth() / 2, _init.getHeight() / 2};
        Logic   _logic{_size};
        int     _fps{9};
        IGraphics*			_lib;
        void*				_dl;
    public:
        Game();
        Game(int size);
        ~Game();
        Game &operator=(Game const &rhs);
        Game(Game const &src);
        void gameplay(); 
        static int map_size_check();
        static int lib_check();
        void			LibSelect(Direction & dir);
};

#endif
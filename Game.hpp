#include "Init.hpp"
#include "Border.hpp"
#include "Score.hpp"
#include "Fruit.hpp"
#include "Snake.hpp"

#include "IGraphics.hpp"
#include "IncGraphics.hpp"
#include "SFMLGraphics.hpp"
#include "IGraphicsSDL.hpp"

#include "Logic.hpp"
#include <ctime>
#include <sys/time.h>
#include <regex>
#include <iostream>
#include "/Users/otimofie/.brew/Cellar/sfml/2.4.2_1/include/SFML/Graphics.hpp" // TODO:user trouble;

#define OUTPUT_RED(x) std::cout << "\033[1;31m" << (x) << "\x1B[0m" << std::endl;
#define OUTPUT_GREEN(x) std::cout << "\033[1;32m" << (x) << "\x1B[0m" << std::endl;

// TODO: 1. comp form in every class which has variables;
// TODO: 2. think about sounds;
// TODO: 3. randomness limits for the fruit;
// TODO: 4. destruct window of sfml;

#ifndef GAME_HPP
#define GAME_HPP

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
    public:
        Game();
        Game(int size);
        ~Game();
        Game &operator=(Game const &rhs);
        Game(Game const &src);
        void gameplay(); 
        void libSelect(IGraphics ** lib, Direction & dir);
        static int map_size_check();
        static int lib_check();
};

#endif
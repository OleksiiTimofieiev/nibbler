#include "Init.hpp"
#include "Border.hpp"
#include "Score.hpp"
#include "Fruit.hpp"
#include "Snake.hpp"

#include "IncGraphics.hpp"
#include "SFMLGraphics.hpp"
#include "IGraphicsSDL.hpp"

#include "Logic.hpp"
#include <ctime>
#include <sys/time.h>
#include "/Users/otimofie/.brew/Cellar/sfml/2.4.2_1/include/SFML/Graphics.hpp" // user trouble;

#define OUTPUT(x) std::cout << (x) << std::endl;

//TODO: comp form in every class;
//TODO: delete all comments
//TODO: APIBase + func to choose lib;

//TODO: obstacles = +, fps fruit = +, esc (enum) = +, user input (check);

// 1. size of the board;
// 2. handle insuffiecient number of arguments (too big, too small, not a number, negative number) -> try | catch block;
// 3. 'q' to escape the game;
// 4. sounds;


// change libraries;


#ifndef GAME_HPP
#define GAME_HPP

class Game
{
    private:
        Init    _init;
        Border  _border;
        Score   _stat;
        Fruit   _fruits{_init.getWidth(), _init.getHeight()};
        Snake   _snake{_init.getWidth() / 2, _init.getHeight() / 2};
        Logic   _logic;
        int     _fps{9};
    public:
        Game();
        ~Game();
        Game &operator=(Game const &rhs);
        Game(Game const &src);
        void gameplay(); 
};

#endif
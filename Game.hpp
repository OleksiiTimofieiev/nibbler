#include "Init.hpp" //TODO: add a separate defin for the classes;
#include "Border.hpp"
#include "Score.hpp"
#include "Fruit.hpp"
#include "Snake.hpp"
#include "IncGraphics.hpp"
#include "Logic.hpp"
#include <ctime>
#include <sys/time.h>

#define OUTPUT(x) std::cout << (x) << std::endl;

//TODO:comp form in every class;
//TODO:delete comments;

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
    public:
        Game();
        ~Game();
        Game &operator=(Game const &rhs);
        Game(Game const &src);
        void gameplay(); 
};

#endif


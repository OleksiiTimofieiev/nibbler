#include "Init.hpp"
#include "Border.hpp"
#include "Score.hpp"
#include "Fruit.hpp"
#include "Snake.hpp"

#include "IncGraphics.hpp"
#include "IGraphicsSDL.hpp"

#include "Logic.hpp"
#include <ctime>
#include <sys/time.h>

#define FPS 30
#define OUTPUT(x) std::cout << (x) << std::endl;

//TODO: comp form in every class;
//TODO: delete all comments;
//TODO: handle stop of the program;
//TODO: better colors;
//TODO: increase fps after fruit eating
//TODO: APIBase + func to choose lib;
//TODO: exit handling;

// TODO: user input
// TODO: wsc key
// TODO:wrong height / width; -> to the user;

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
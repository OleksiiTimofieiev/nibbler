#include "Init.hpp" //TODO: add a separate defin for the classes;
#include "Border.hpp"
#include "Score.hpp"
#include "Fruit.hpp"
#include "Snake.hpp"

#ifndef GAME_HPP
#define GAME_HPP

class Game
{
    private:
        Init    _init;
        Border  _border;
        Score   _stat;
        Fruit   _fruits;
        Snake   _snake;
    public:
        Game();
        ~Game();

    //TODO:copl form;
        
};

#endif


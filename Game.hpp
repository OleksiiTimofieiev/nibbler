#include "Init.hpp" //TODO: add a separate defin for the classes;
#include "Border.hpp"
#include "Score.hpp"
#include "Fruit.hpp"
#include "Snake.hpp"
#include "IncGraphics.hpp"

#ifndef GAME_HPP
# define GAME_HPP

class Game
{
    private:
        Init    _init;
        Border  _border;
        Score   _stat;
        Fruit   _fruits; //pseudo random;
        Snake   _snake{_init.getWidth() / 2, _init.getHeight() / 2};
    public:
        Game();
        ~Game();

    void gameplay();

      //TODO:copl form;
        
};

#endif


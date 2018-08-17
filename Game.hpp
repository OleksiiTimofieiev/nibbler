#include "Init.hpp" //TODO: add a separate defin for the classes;
#include "Border.hpp"
#include "Score.hpp"

#ifndef GAME_HPP
#define GAME_HPP

// enum direction
// {
//     STOP = 0,
//     LEFT,
//     RIGHT,
//     UP,
//     DOWN
// };

class Game
{
    private:
        Init    _init;
        Border  _border;
        Score   _score;
        // Snake   _snake(x,y); // reference for class;
        // Fruit _fruits;
        // Score _stat;

        
        // direction   _dir; // to the logic or visu;

        // vector<GraphicModules> // 3 instances of the class with a concretemethods; functions
        
        // enum bla = STOP;

        // public : Game(int graphic module);
        // void    gameplay()
        // {
        //     GraphicModules[lib]->draw(Snake & snake, Fruit & fruit, wall)
        //     bla = GraphicModules[lib]->get_ivent();
        // }
    public:
        Game();
        ~Game();

    //TODO:copl form;
        
};

#endif


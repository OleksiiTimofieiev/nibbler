#ifndef GAME_HPP
#define GAME_HPP

enum direction
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

class Game
{
    private:
        


        Init _init(x, y); // bool _gameOver; const int width; const int _height;
        Snake   _snake(x,y);
        Border  _border(x,y);
        vector<Fruit> fruits;
        Score _score;

        
        direction   _dir; // to the logic or visu;


        vector<GraphicModules> // 3 instances of the class with a concretemethods; functions 


      public:
        Game(int graphic module);
        void    gameplay()
        {
            GraphicModules[lib]->draw(Snake & snake, Fruit & fruit, wall)
            {

                drawSnake(snake)
            }
        }
        
}







#endif


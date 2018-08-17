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
        
        direction   _dir;

        Score _score;

        vector<GraphicModules> // 3 instances;


      public:
        Game(int graphic module);
        void    gameplay();
        
}







#endif


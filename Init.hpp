#ifndef INIT_HPP
#define INIT_HPP

#define WIDTH 20
#define HEIGHT 20

class   Init
{
    bool  _gameOver;
    int   _width;
    int   _height;

    public:
        Init();
        Init(int size);
        ~Init();
        Init &operator=(Init const &rhs);
        Init(Init const &src);
        bool getGameOver();
        int  getWidth();
        int  getHeight();
        void setGameStatus();
};

#endif
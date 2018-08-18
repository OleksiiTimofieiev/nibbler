#ifndef INIT_HPP
#define INIT_HPP

#define WIDTH 125
#define HEIGHT 40

class   Init
{
    bool  _gameOver;
    int   _width;
    int   _height;

    public:
        Init();
        ~Init();
        Init &operator=(Init const &rhs);
        Init(Init const &src);
        bool getGameOver();
        int  getWidth();
        int  getHeight();
        void setGameStatus();
};

#endif
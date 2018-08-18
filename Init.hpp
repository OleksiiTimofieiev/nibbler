#ifndef INIT_HPP
#define INIT_HPP

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
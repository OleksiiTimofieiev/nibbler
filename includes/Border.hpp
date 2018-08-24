#ifndef BORDER_HPP
#define BORDER_HPP

class Border
{
    int _width;
    int _height;

    public:
        Border();
        Border(int size);
        ~Border();
        Border &operator=(Border const &rhs);
        Border(Border const &src);
        int getWidth();
        int getHeight();
};

#endif
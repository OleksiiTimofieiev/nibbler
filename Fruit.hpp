#ifndef FRUIT_HPP
#define FRUIT_HPP

class Fruit
{
    int _width;
    int _height;

    public:
        Fruit();
        ~Fruit();
        Fruit &operator=(Fruit const &rhs);
        Fruit(Fruit const &src);
        int getWidth();
        int getHeight();
};

#endif

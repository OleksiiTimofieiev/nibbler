#ifndef FRUIT_HPP
#define FRUIT_HPP

#include <utility>
#include <iostream>

class Fruit
{
    std::pair<int, int> _coords;

    public:
        Fruit();
        Fruit(int x, int y);
        ~Fruit();
        Fruit &operator=(Fruit const &rhs);
        Fruit(Fruit const &src);
        std::pair<int, int> getCoords();
        void setCoords(int x, int y);
        
};

#endif

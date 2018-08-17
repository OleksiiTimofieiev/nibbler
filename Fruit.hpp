#ifndef FRUIT_HPP
#define FRUIT_HPP

#include <utility>

class Fruit
{
    std::pair<int, int> _coords;

    public:
        Fruit();
        ~Fruit();
        Fruit &operator=(Fruit const &rhs);
        Fruit(Fruit const &src);
        std::pair<int, int> getCoords();
};

#endif

#include "Fruit.hpp"

Fruit::~Fruit(){};
Fruit::Fruit(){
    _coords.first = 0;
    _coords.second = 0;
};

Fruit &Fruit::operator=(Fruit const &rhs)
{
    if (this != &rhs)
    {
        _coords = rhs._coords;
    }
    return *this;
}

Fruit::Fruit(Fruit const &src)
{
    *this = src;
}

std::pair<int,int> Fruit::getCoords() { return _coords; }
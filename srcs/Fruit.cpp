#include "../includes/Fruit.hpp"

Fruit::Fruit(){};
Fruit::~Fruit(){};

Fruit::Fruit(int x, int y)
{
    srand(clock());
    _coords.first = rand() % x;
    _coords.second = rand() % y;
};

Fruit &Fruit::operator=(Fruit const &rhs)
{
    if (this != &rhs)
        _coords = rhs._coords;
    return *this;
}

Fruit::Fruit(Fruit const &src)
{
    *this = src;
}

std::pair<int,int> Fruit::getCoords() { return _coords; }

void Fruit::setCoords(int x, int y)
{ 
    _coords.first = x;
    _coords.second = y;
}

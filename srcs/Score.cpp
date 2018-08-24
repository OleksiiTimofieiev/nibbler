#include "../includes/Score.hpp"

Score::~Score(){};
Score::Score() : _score(0){};

Score &Score::operator=(Score const &rhs)
{
    if (this != &rhs)
    {
        _score = rhs._score;
    }
    return *this;
}

Score::Score(Score const &src)
{
    *this = src;
}

int Score::getScore() { return _score; }
void    Score::setScore() { _score += 10;}

void Score::show()
{
    std::cout << "Your score is: " << _score << std::endl;
    std::cout << "Your reached level is: " << _score / 10 << std::endl;
}

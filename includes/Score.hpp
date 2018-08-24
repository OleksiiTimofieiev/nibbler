#ifndef SCORE_HPP
#define SCORE_HPP

#include <iostream>

class Score
{
    int _score;

    public:
        Score();
        ~Score();
        Score &operator=(Score const &rhs);
        Score(Score const &src);
        int getScore();
        void    setScore();
        void    show();
};

#endif
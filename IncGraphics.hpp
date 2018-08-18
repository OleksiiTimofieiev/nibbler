#ifndef INCGRAPHICS_HPP
# define INCGRAPHICS_HPP

# include "Game.hpp"
# include "IGraphics.hpp"
# include <iostream>
# include <unistd.h>
# include <time.h>
# include <sys/utsname.h>
# include <ncurses.h>
# include <sys/types.h>
# include <sys/sysctl.h>
#include <locale.h>
#include <wchar.h>

class IncGraphics : public IGraphics
{
    public:
        IncGraphics();
        IncGraphics(IncGraphics const &);
        ~IncGraphics();

        IncGraphics &operator=(IncGraphics const &ref);

        void Draw(Snake &snake, Fruit &fruit, Score &score, Init &init) const;
        void DrawSnake(Snake &snake) const;
        void DelSnake(Snake &snake) const;
        Direction CheckEvent(Direction &dr) const;
        void DrawFruit(Fruit &fruit) const;
        // void DrawWall(const IObject &) const;

        void DrawMap(Border &border) const;
};

#endif
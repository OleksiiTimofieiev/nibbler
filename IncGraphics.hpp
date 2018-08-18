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

class IncGraphics : public IGraphics
{
    public:
        IncGraphics();
        IncGraphics(IncGraphics const &);
        ~IncGraphics();

        IncGraphics &operator=(IncGraphics const &ref);

        void Draw(Snake &snake, Fruit &fruit, Score &score, Init &init) const;
        void DrawSnake(Snake &snake, Init &init) const;
        Direction CheckEvent(Direction &dr) const;
        // void DrawFruit(const IObject &) const;
        // void DrawWall(const IObject &) const;

        void DrawMap(Border &border) const;
};

#endif
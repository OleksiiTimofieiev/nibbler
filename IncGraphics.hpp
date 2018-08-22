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

        void Draw(Snake &snake, Fruit &fruit, Score &score, Init &init);
        void DrawSnake(Snake &snake);
        void DelSnake(Snake &snake);
        Direction CheckEvent(Direction &dr);
        void DrawFruit(Fruit &fruit);
        // void DrawWall(const IObject &);

        void DrawMap(Border &border);
};

#endif
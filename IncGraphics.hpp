#ifndef INCGRAPHICS_HPP
# define INCGRAPHICS_HPP

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

        // void Draw(std::vector<const IObject> &) const;
        // void DrawSnake(const IObject &) const;
        // void DrawFruit(const IObject &) const;
        // void DrawWall(const IObject &) const;

        void DrawMap(int height, int width) const;
};

#endif
#ifndef IGRAPHICSNCURSES_HPP
# define IGRAPHICSNCURSES_HPP

# include "../includes/Game.hpp"
# include "../includes/IGraphics.hpp"
# include <iostream>
# include <unistd.h>
# include <time.h>
# include <sys/utsname.h>
# include <ncurses.h>
# include <sys/types.h>
# include <sys/sysctl.h>
# include <locale.h>
# include <wchar.h>

class IGraphicsNCURSES : public IGraphics
{
    public:
        IGraphicsNCURSES();
        IGraphicsNCURSES(IGraphicsNCURSES const &);
        ~IGraphicsNCURSES();

        IGraphicsNCURSES &operator=(IGraphicsNCURSES const &ref);

        void Draw(Snake &snake, Fruit &fruit, Score &score, Init &init);
        void DrawSnake(Snake &snake);
        void DelSnake(Snake &snake);
        Direction CheckEvent(Direction &dr);
        void DrawFruit(Fruit &fruit);
        void DrawMap(Border &border);
        void DrawMap(Init &init);        
        void DrawObstacle(Snake &snake);
};

#endif
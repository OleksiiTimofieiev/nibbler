#ifndef IGRAPHICS_HPP
# define IGRAPHICS_HPP

class IGraphics
{       
    public:
        // virtual void Draw(Snake &snake, Fruit &fruit, Score &score, Init &init) const = 0;
        // virtual void DrawSnake(Snake &snake) const = 0;
        // virtual Direction CheckEvent(Direction &dr) const = 0;
        // virtual void DrawFruit(Fruit &fruit) const = 0;
        // virtual void DrawWall(const IObject &) const = 0;
        // virtual void DrawMap(Border &border) const = 0;
        virtual ~IGraphics(void) {}
};

#endif
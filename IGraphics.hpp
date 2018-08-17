#ifndef IGRAPHICS_HPP
# define IGRAPHICS_HPP

class IGraphics
{       
    public:
        virtual void Draw(Fruit &fruit, Score &score, Init &init) const = 0;
        // virtual void DrawSnake(const IObject &) const = 0;
        // virtual void DrawFruit(const IObject &) const = 0;        
        // virtual void DrawWall(const IObject &) const = 0;

        virtual void DrawMap(Border &border) const = 0;

        virtual ~IGraphics(void) {}
};

#endif
#ifndef IGRAPHICS_HPP
# define IGRAPHICS_HPP

class IGraphics
{       
    public:
        virtual void Draw(Snake &snake, Fruit &fruit, Score &score, Init &init) = 0;
        virtual void DrawSnake(Snake &snake)  = 0;
        virtual Direction CheckEvent(Direction &dr) = 0;
        virtual void DrawFruit(Fruit &fruit) = 0;
        virtual void DrawMap(Border &border) = 0;
        virtual ~IGraphics() {};
};

#endif
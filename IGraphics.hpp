#ifndef IGRAPHICS_HPP
# define IGRAPHICS_HPP

class IGraphics
{       
    public:
        // virtual void Draw(std::vector<const IObject> &) const = 0;
        // virtual void DrawSnake(const IObject &) const = 0;
        // virtual void DrawFruit(const IObject &) const = 0;        
        // virtual void DrawWall(const IObject &) const = 0;

        virtual void DrawMap() const = 0;

        virtual ~IGraphics(void) {}
};

#endif
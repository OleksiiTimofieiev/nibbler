#ifndef IGRAPHICSSDL_HPP
#define IGRAPHICSSDL_HPP

// #include "Game.hpp"
#include "Game.hpp"
#include "IGraphics.hpp"
#include "/Library/Frameworks/SDL2.framework/Versions/A/Headers/SDL.h"
#include <iostream>

class IGraphicsSDL : public IGraphics
{
    public:
        IGraphicsSDL();
        ~IGraphicsSDL();
            // IGraphicsSDL(IGraphicsSDL const & rhs);
            // ~IGraphicsSDL();

            // IGraphicsSDL &operator=(IGraphicsSDL const &ref);

            void Draw(Snake &snake, Fruit &fruit, Score &score, Init &init) ;
            void DrawSnake(Snake &snake) ;
            void DelSnake(Snake &snake) const;
            Direction CheckEvent(Direction &dr) const;
            void DrawFruit(Fruit &fruit) const;
            void DrawMap(Border &border);
    private: 
        SDL_Window *_window = nullptr;
        SDL_Renderer *_renderer = nullptr;
    };

#endif
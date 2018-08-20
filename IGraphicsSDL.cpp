#include "IGraphicsSDL.hpp"

IGraphicsSDL::IGraphicsSDL()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "Failed to create a window." << std::endl;
        //TODO: exit the program;
    }
}

void IGraphicsSDL::DrawMap(Border &border)
{
    SDL_Surface *screenSurface = NULL;

    _window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, border.getWidth(), border.getWidth(), SDL_WINDOW_SHOWN);

    if (_window == nullptr)
    {
        std::cout << "Failed to create a window." << std::endl;
        //TODO: exit the program;
    }
    //Get window surface
    screenSurface = SDL_GetWindowSurface(_window);

    //Fill the surface white
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

    //Update the surface
    SDL_UpdateWindowSurface(_window);
}
//TODO: replace, make void func, add chars to the options;
Direction IGraphicsSDL::CheckEvent(Direction &dr) const
{
    SDL_Event event;

    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
            {
               dr = stop; // TODO: remaster
            }
        }
    }
    return dr;
}


IGraphicsSDL::~IGraphicsSDL()
{
    SDL_DestroyWindow(_window); 
    SDL_Quit();
}
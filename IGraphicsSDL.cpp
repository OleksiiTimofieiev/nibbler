#include "IGraphicsSDL.hpp"

IGraphicsSDL::IGraphicsSDL()
{
    SDL_Surface *screenSurface = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "Failed to create a window." << std::endl;
        //TODO: exit the program;
    }
    _window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

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

    //Wait two seconds
    SDL_Delay(2000);
}

//TODO: replace
Direction IGraphicsSDL::CheckEvent(/*Direction &dr*/) const
{
    SDL_Event event;

    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                return stop; // TODO: remaster
            default: break;
        }
    }
    return up; //TODO:
}

IGraphicsSDL::~IGraphicsSDL()
{
    SDL_DestroyWindow(_window); 
    SDL_Quit();
}
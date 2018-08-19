#include "IGraphicsSDL.hpp"

IGraphicsSDL::IGraphicsSDL()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "Failed to create a window." << std::endl;
        //TODO: exit the program;
    }
    _window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 125, 40, 0);

    if (_window == nullptr)
    {
        std::cout << "Failed to create a window." << std::endl;
        //TODO: exit the program;
    }
}

IGraphicsSDL::~IGraphicsSDL()
{
    SDL_DestroyWindow(_window); 
    SDL_Quit();
}
#include "IGraphicsSDL.hpp"

// SDL_Rect rect;
// SDL_Rect rect2;
// SDL_Rect rect3;

// rect.w = 10;
// rect.h = 10;
// rect.x = border.getWidth() / 2 - rect.w / 2;
// rect.y = border.getHeight() / 2 - rect.h / 2;

// rect2.w = 10;
// rect2.h = 10;
// rect2.x = border.getWidth() / 2 - rect.w / 2;
// rect2.y = border.getHeight() / 2 - rect.h / 2 + 15;

// SDL_SetRenderDrawColor(_renderer, 200, 0, 200, 255);

// SDL_RenderFillRect(_renderer, &rect);
// SDL_RenderFillRect(_renderer, &rect2);

// SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);

// rect3.w = 10;
// rect3.h = 10;
// rect3.x = border.getWidth() / 2 - rect3.w / 2;
// rect3.y = border.getHeight() / 2 - rect3.h / 2 + 30;

// SDL_RenderFillRect(_renderer, &rect3);

IGraphicsSDL::IGraphicsSDL()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "Failed to create a window. Program will be terminated." << std::endl;
        exit(0);
    }
}

IGraphicsSDL::~IGraphicsSDL()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void IGraphicsSDL::DrawMap(Border &border)
{
    _window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, border.getWidth(), border.getWidth(), SDL_WINDOW_SHOWN);

    if (_window == nullptr)
    {
        std::cout << "Failed to create a window. Program will be terminated." << std::endl;
        exit(0);
    }



    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255); // backscreen color;
    SDL_RenderClear(_renderer);
    SDL_RenderPresent(_renderer);
    
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

    // int key = 0;

    // key = getch();
    // // if (key == 113)
    // // {
    // // 	refresh();
    // // 	system("reset");
    // // 	exit(1);
    // // }
    // if (key == 115) // key W
    //     dr = down;
    // else if (key == 119) // key S
    //     dr = up;
    // else if (key == 97) // key D
    //     dr = left;
    // else if (key == 100) // key A
    //     dr = right;
    // return (dr);

    return dr;
}



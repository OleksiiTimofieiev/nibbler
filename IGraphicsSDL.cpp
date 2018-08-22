#include "IGraphicsSDL.hpp"

// static int change_y = 0;
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
    _window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, border.getWidth() * 16, border.getHeight() * 16, SDL_WINDOW_SHOWN);

    if (_window == nullptr)
    {
        std::cout << "Failed to create a window. Program will be terminated." << std::endl;
        exit(0);
    }

    _renderer = SDL_CreateRenderer(_window, -1, 0);
}

Direction IGraphicsSDL::CheckEvent(Direction &dr) const
{
    SDL_Event event;

    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
            {
                dr = stop_the_game;
                break;
            }
            case SDL_KEYDOWN:
            {
                switch(event.key.keysym.sym)
                {
                    case SDLK_a:
                    {
                        dr = left;
                        break;
                    }
                    case SDLK_d:
                    {
                        dr = right;
                        break;
                    }
                    case SDLK_w:
                    {
                        dr = up;
                        break;
                    }
                    case SDLK_s:
                    {
                        dr = down;
                        break;
                    }
                    case SDLK_q:
                    {
                        dr = stop_the_game;
                        break;
                    }
                }
            }
        }
    }
    return (dr);
}

void IGraphicsSDL::Draw(Snake &snake, Fruit &fruit, Score &score, Init &init)
{
    (void)score;
    (void)init;

    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255); // backscreen color;
    SDL_RenderClear(_renderer);

    DrawSnake(snake);
    DrawFruit(fruit);

    SDL_RenderPresent(_renderer);
}

void IGraphicsSDL::DrawSnake(Snake &snake)
{
    SDL_RenderClear(_renderer);

    SDL_Rect rect;

    std::pair<int, int> head = snake.getHeadCoords();
    std::vector<std::pair<int, int> > tail = snake.getTailCoords();

    rect.w = 16;
    rect.h = 16;
    rect.x = head.first * 16;
    rect.y = head.second * 16;

    SDL_SetRenderDrawColor(_renderer, 200, 0, 200, 255);
    SDL_RenderFillRect(_renderer, &rect);

    for (int i = 0; i < snake.getTailLen(); i++)
    {
        rect.x = tail[i].first * 16;
        rect.y = tail[i].second * 16;


        SDL_SetRenderDrawColor(_renderer, 0, 0, 200, 255);
        SDL_RenderFillRect(_renderer, &rect);
    }
}

void IGraphicsSDL::DrawFruit(Fruit &fruit) const
{
    SDL_Rect rect;

    std::pair<int, int> crd = fruit.getCoords();
    rect.w = 16;
    rect.h = 16;
    rect.x = crd.first * 16;
    rect.y = crd.second * 16;
    SDL_SetRenderDrawColor(_renderer, 0, 0, 200, 255);

    SDL_RenderFillRect(_renderer, &rect);
}

void IGraphicsSDL::DelSnake(Snake &snake) const
{
    (void)snake;
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255); // backscreen color;
    SDL_RenderClear(_renderer);
}


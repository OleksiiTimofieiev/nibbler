#include "IGraphicsSDL.hpp"

extern "C" IGraphics *NewDisplay(void)
{
    return (new IGraphicsSDL());
}

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

Direction IGraphicsSDL::CheckEvent(Direction &dr)
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
                    case SDLK_e:
                    {
                        dr = change_the_lib;
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

void IGraphicsSDL::Draw(Snake & snake, Fruit & fruit, Score & score, Init & init)
{
    (void)score;
    (void)init;

    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
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

    std::vector<std::pair<int, int> > obstacles = snake.getObstacleCoords();

    for (int i = 0; i < 5; i++)
    {
        rect.x = obstacles[i].first * 16;
        rect.y = obstacles[i].second * 16;

        SDL_SetRenderDrawColor(_renderer, 0, 200, 0, 255);
        SDL_RenderFillRect(_renderer, &rect);
    }
}

void IGraphicsSDL::DrawFruit(Fruit &fruit)
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

void IGraphicsSDL::DelSnake(Snake &snake)
{
    (void)snake;
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255); // backscreen color;
    SDL_RenderClear(_renderer);
}


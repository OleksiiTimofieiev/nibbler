#include "IGraphicsSDL.hpp"

static int change_y = 0;
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

    _renderer = SDL_CreateRenderer(_window, -1, 0);
}

Direction IGraphicsSDL::CheckEvent(Direction &dr) const
{
    SDL_Event event;

    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
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
                }
            }
        }
    }
    return (dr);
}

void IGraphicsSDL::Draw(Snake &snake, Fruit &fruit, Score &score, Init &init)
{
    (void)fruit;
    (void)score;
    (void)init;

    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255); // backscreen color;
    SDL_RenderClear(_renderer);

    // if (snake.getDir() != stop) //TODO: maybe do not need;
    //     DelSnake(snake);
    DrawSnake(snake);
    // DrawFruit(fruit);
    SDL_RenderPresent(_renderer);
}

void IGraphicsSDL::DrawSnake(Snake &snake)
{
    SDL_RenderClear(_renderer);



    SDL_Rect rect;

    std::pair<int, int> head = snake.getHeadCoords();
    std::vector<std::pair<int, int> > tail = snake.getTailCoords();

    int buf_x_coord = head.first;
    int buf_y_coord = head.second;

    rect.w = 10;
    rect.h = 10;

    if (snake.getDir() == left)
    {
        rect.x = head.first;
        rect.y = head.second;

        SDL_SetRenderDrawColor(_renderer, 200, 100, 200, 255);
        SDL_RenderFillRect(_renderer, &rect);

        for (int i = 0, buf_y = 12, buf_x = 12; i < snake.getTailLen(); i++)
        {
            if (tail[i].first != buf_x_coord && buf_y_coord == tail[i].second) // for stop;
            {
                rect.x = tail[i].first + buf_x;
                rect.y = tail[i].second;
                buf_x += 11;
            }
            if (tail[i].first == buf_x_coord && buf_y_coord != tail[i].second) // for stop;
            {
                rect.x = tail[i].first + buf_x;
                rect.y = tail[i].second + buf_y;
                buf_y+=11;
            }

            buf_x_coord = tail[i].first;
            buf_y_coord = tail[i].second;

            //TODO:del
            // std::cout << rect.x << std::endl;
            // std::cout << rect.y << std::endl;
            // SDL_Delay(5000);
            SDL_SetRenderDrawColor(_renderer, 0, 0, 200, 255);

            SDL_RenderFillRect(_renderer, &rect);
        }
    }
    if (snake.getDir() == stop)
    {
        rect.x = head.first;
        rect.y = head.second;

        SDL_SetRenderDrawColor(_renderer, 200, 100, 200, 255);
        SDL_RenderFillRect(_renderer, &rect);

        for (int i = 0, buf_y = 11; i < snake.getTailLen(); i++) 
        {

                rect.x = tail[i].first;
                rect.y = tail[i].second + buf_y;
                buf_y += 11;

            //TODO:del
            // std::cout << rect.x << std::endl;
            // std::cout << rect.y << std::endl;
            // SDL_Delay(5000);
                SDL_SetRenderDrawColor(_renderer, 0, 0, 200, 255);

                SDL_RenderFillRect(_renderer, &rect);
        }
    }
    if (snake.getDir() == down)
    {
        int buf_y = 0;
        int buf_x_coord_2 = head.first;
        int buf_y_coord_2 = head.second;

        for (int i = 0; i < snake.getTailLen(); i++) // get the head correction on y;
        {
            if ( buf_y_coord_2 != tail[i].second )
                buf_y++;

            buf_x_coord_2 = tail[i].first;
            buf_y_coord_2 = tail[i].second;
        }

        buf_y *= 12;

        rect.x = head.first;
        rect.y = head.second + buf_y;

        int megabuff_y = rect.y;


        change_y = buf_y;

        SDL_SetRenderDrawColor(_renderer, 200, 100, 200, 255);
        SDL_RenderFillRect(_renderer, &rect);

        std::cout << buf_y << std::endl;

        buf_x_coord_2 = head.first;
        buf_y_coord_2 = head.second;

        for (int i = 0, buf_x = 12; i < snake.getTailLen(); i++) // 12 make a define;
        {
            if (tail[i].first == buf_x_coord_2 && buf_y_coord_2 != tail[i].second)
            {
                megabuff_y -= 12;
                rect.x = tail[i].first;
                rect.y = megabuff_y;
                std::cout << "rect.y -> "<< rect.y << std::endl;
            }
            else if (buf_y_coord_2 == tail[i].second && tail[i].first != buf_x_coord_2)
            {
                rect.x = tail[i].first + buf_x;
                rect.y = tail[i].second;

                buf_x += 12;
            }

            buf_x_coord_2 = tail[i].first;
            buf_y_coord_2 = tail[i].second;

            //TODO:del
            // std::cout << rect.x << std::endl;
            // std::cout << rect.y << std::endl;
            // SDL_Delay(5000);

            SDL_SetRenderDrawColor(_renderer, 0, 0, 200, 255);
            SDL_RenderFillRect(_renderer, &rect);
        }
    }
}

void IGraphicsSDL::DelSnake(Snake &snake) const
{
    (void)snake;
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255); // backscreen color;
    SDL_RenderClear(_renderer);
}
#include "../includes/Game.hpp"

int     main(void)
{
    Game _game(Game::map_size_check());
    
    _game.gameplay();

    return (0);
}

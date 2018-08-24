#include "../includes/includes.hpp"

int     main(void)
{
    Game _game(Game::map_size_check());
    
    _game.gameplay();

    system("leaks nibbler");

    return (0);
}

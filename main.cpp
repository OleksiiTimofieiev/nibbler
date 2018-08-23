#include "includes.hpp"

int     main(void)
{
    int size;

    std::cout << "Please, enter the size of the board." << std::endl;

    std::cin >> size;

    Game _game(size);

    _game.gameplay();

    return (0);
}

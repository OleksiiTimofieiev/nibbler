clang++ -std=c++11 -rpath ~/.brew/Cellar/sfml/2.4.2_1/lib/ -I ~/.brew/Cellar/sfml/2.4.2_1/include/ -L ~/.brew/Cellar/sfml/2.4.2_1/lib/ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network -Wall -Wextra -Werror Game.cpp Fruit.cpp Score.cpp Snake.cpp Init.cpp IGraphicsNCURSES.cpp Border.cpp Logic.cpp IGraphicsSDL.cpp IGraphicsSFML.cpp main.cpp -I/Library/Frameworks/SDL2.framework/Headers -F/Library/Frameworks -framework SDL2 -lm -lncurses && ./a.out

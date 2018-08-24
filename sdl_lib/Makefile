NAME 		=	sdl_lib.so

COM			=	clang++
FLAGS		=	-std=c++11 -Wall -Wextra -Werror -O3

SDL_DIR		=	./SDL
SDL_FRM		=	-F $(SDL_DIR)
SDL_LINK	=	-framework SDL2

PWD			= 	$(shell pwd)
LIB_FLAG	=	-shared  -rpath $(PWD)/$(SDL_DIR) -nostartfiles -dynamiclib

SRC_FILES	=	../srcs/Border.cpp \
				../srcs/Fruit.cpp  \
				../srcs/Init.cpp   \
				../srcs/Game.cpp   \
				../srcs/Logic.cpp  \
				../srcs/main.cpp   \
				../srcs/Score.cpp  \
				../srcs/Snake.cpp  \
				IGraphicsSDL.cpp

INC_FILES	=	IGraphicsSDL.hpp

INC_DIR		=	../includes

OBJ_FILES	= 	$(SRC_FILES:.cpp=.cpp.o)

SDL2 		=	SDL2

all: sdl $(NAME)

$(NAME): $(OBJ_FILES)
	@ $(COM) $(FLAGS) $(SDL_FRM) $(SDL_LINK) $(LIB_FLAG) $(OBJ_FILES) -o $(NAME)

%.cpp.o:%.cpp
	@ $(COM) $(FLAGS) $(SDL_FRM) -c -o $@ $< -I $(INC_DIR)


sdl:
	@ mkdir -p $(SDL_DIR)
	@ test -f SDL/SDL2.framework/SDL2 && echo "\033[33mFile $(SDL2) already exist\033[39m" || make sdl2_download

sdl2_download:
	echo "\033[32m... loading SDL\033[39m"
	@ curl -o sdl2.dmg https://www.libsdl.org/release/SDL2-2.0.8.dmg
	@ hdiutil attach sdl2.dmg;
	@ cd ; cp -R -i ../../../Volumes/SDL2/SDL2.framework $(PWD)/$(SDL_DIR)/SDL2.framework; hdiutil eject ../../../Volumes/SDL2;
	@ rm -rf sdl2.dmg

clean:
	@ rm -rf $(OBJ_FILES)
	@ rm -fr $(SDL_DIR)
	@ echo "\033[33mcleaned (SDL)\033[39m"

fclean:	clean
	@ rm -rf $(NAME)
	@ echo "\033[33mcleaned all (SDL)\033[39m"
	
re:	fclean all

.PHONY: all sdl clean fclean re
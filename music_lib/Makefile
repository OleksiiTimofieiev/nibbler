NAME 		=	music_lib.so

CLANG++		=	clang++
FLAGS 		=	-std=c++11 -Wall -Wextra -Werror -O3

LIB_FLAG	=	-shared -nostartfiles -dynamiclib

SRC_FILES	=	MusicClass.cpp

INC_FILES	=	MusicClass.hpp

INC_DIR		=	../includes/

OBJ_FILES 	=	$(SRC_FILES:.cpp=.cpp.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@ $(CLANG++) $(FLAGS) -o $@ $(OBJ_FILES) $(LIB_FLAG)

%.cpp.o:%.cpp
	@ $(CLANG++) $(FLAGS) -c -o $@ $< -I $(INC_DIR)


clean:
	@ rm -rf $(OBJ_FILES)
	@ echo "\033[33mcleaned (MUSIC)\033[39m"

fclean: clean
	@ rm -rf $(NAME)
	@ echo "\033[33mcleaned all (MUSIC)\033[39m"

re: fclean all

.PHONY: all sfml sfml_dl clean fclean re
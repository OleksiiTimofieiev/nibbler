NAME 		=	ncurses_lib.so

CLANG++			=	clang++
FLAGS		=	-std=c++11 -Wall -Wextra -Werror -O3
LIB_FLAGS	=	-shared -nostartfiles -dynamiclib -lm -lncurses

SRC	=	../srcs/Border.cpp \
  		../srcs/Fruit.cpp  \
		../srcs/Init.cpp   \
  		../srcs/Game.cpp   \
  		../srcs/Logic.cpp  \
  		../srcs/main.cpp   \
  		../srcs/Score.cpp  \
  		../srcs/Snake.cpp  \
		IGraphicsNCURSES.cpp

INC	=	IGraphicsNCURSES.hpp

INC_DIR		=	../includes/

OBJ	= $(SRC:.cpp=.cpp.o)

all: $(NAME)

%.cpp.o:%.cpp
	$(CLANG++) $(FLAGS) -c $< -o $@ -I $(INC_DIR)

$(NAME): $(OBJ) $(INC)
		@$(CLANG++) $(FLAGS)$(LIB_FLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJ)
	@ echo "\033[33mcleaned (ncurses)\033[39m"

fclean:	clean
	@rm -rf $(NAME)
	@ echo "\033[33mcleaned all (ncurses)\033[39m"

re:		fclean all

.PHONY: all clean fclean re

# ../includes/Border.hpp \
# 				../includes/Fruit.hpp  \
# 				../includes/Game.hpp   \
# 				../includes/init.hpp   \
# 				../includes/Logic.hpp  \
# 				../includes/main.hpp   \
# 				../includes/Score.hpp  \
# 				../includes/Snake.hpp  \

# ../srcs/Border.cpp \
# 		../srcs/Fruit.cpp  \
# 		../srcs/Game.cpp   \
# 		../srcs/init.cpp   \
# 		../srcs/Logic.cpp  \
# 		../srcs/main.cpp   \
# 		../srcs/Score.cpp  \
# 		../srcs/Snake.cpp  \
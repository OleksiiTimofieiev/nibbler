NAME		=	nibbler

CLANG++		=	clang++
FLAGS		=	-std=c++11 -Wall -Wextra -Werror -O3

DL			=	-rdynamic
LINK		=	-ldl

SRC_DIR		=	./srcs/
INC_DIR		=	./includes/
OBJ_DIR		=	./obj/

SRC	= 			Border.cpp \
				Fruit.cpp  \
				Init.cpp   \
				Game.cpp   \
				Logic.cpp  \
				main.cpp   \
				Score.cpp  \
				Snake.cpp

INC 	= 		Border.hpp \
				Fruit.hpp  \
				Init.hpp   \
				Game.hpp   \
				Logic.hpp  \
				Score.hpp  \
				Snake.hpp

OBJ 	=	$(SRC:.cpp=.cpp.o)

SRCS 		=	$(addprefix $(SRC_DIR), $(SRC))
HDRS 		=	$(addprefix $(INC_DIR), $(INC))
OBJS 		= 	$(addprefix $(OBJ_DIR), $(OBJ))

all: obj $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.cpp.o:$(SRC_DIR)%.cpp
	$(CLANG++) $(FLAGS) -c $< -o $@ -I $(INC_DIR)

$(NAME): ncss sfml sdl music $(OBJS) $(HDRS)
	@$(CLANG++) $(FLAGS) $(DL) $(OBJS) -o $(NAME) $(LINK)

sfml:
	@make -C ./sfml_lib/
	@echo "\033[32mSFML Builded\033[39m"

sdl:
	@make -C ./sdl_lib/
	@echo "\033[32mSDL Builded\033[39m"

ncss:
	@make -C ./ncurses_lib/
	@echo "\033[32mNcurses Builded\033[39m"

music:
	@make -C ./music_lib/
	@echo "\033[32mMusic Builded\033[39m"

clean:
	@make -C ncurses_lib clean
	@make -C sdl_lib clean
	@make -C sfml_lib clean
	@make -C music_lib clean
	
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_DIR)

fclean:
	@make -C ncurses_lib fclean
	@make -C sdl_lib fclean
	@make -C sfml_lib fclean
	@make -C music_lib fclean
	
	@rm -rf $(NAME)
	@echo "\033[33mCLEANED ALL\033[39m"

re:		fclean all

.PHONY: all ncurses sdl sfml music clean fclean re
NAME		=	nibbler

CLANG++			=	clang++
FLAGS		=	-std=c++11 -Wall -Wextra -Werror -O3

DL_FLAG		=	-rdynamic
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

GREEN		=	\033[32m
RESET		=	\033[39m
YELLOW		=	\033[33m
RED 		=	\033[31m

all: obj $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.cpp.o:$(SRC_DIR)%.cpp
	$(CLANG++) $(FLAGS) -c $< -o $@ -I $(INC_DIR)

$(NAME): ncurses $(OBJS) $(HDRS)
	@$(CLANG++) $(FLAGS) $(DL_FLAG) $(OBJS) -o $(NAME) $(LINK)

ncurses:
	@make -C ./ncurses_lib/
	@echo "$(GREEN)Build Ncurses: OK$(RESET)"

# sdl:
# 	@make -C ./lib_sdl/
# 	@echo "$(GREEN)Build SDL: OK$(RESET)"

# sfml:
# 	@make -C ./lib_sfml/
# 	@echo "$(GREEN)Build SFML: OK$(RESET)"

clean:
	@make -C ncurses_lib clean
	# @make -C lib_sdl clean
	# @make -C lib_sfml clean
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C ncurses_lib fclean
	# @make -C lib_sdl fclean
	# @make -C lib_sfml fclean
	@rm -rf $(NAME)
	@echo "$(RED)Attention: $(RESET)$(NAME) was removed"

re:		fclean all

.PHONY: all ncurses sdl sfml clean fclean re
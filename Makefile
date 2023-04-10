NAME				= philo
CC					= clang
CFLAGS				= -Wall -Wextra -Werror -I$(LIBFT_DIR) -I$(INCLUDE_DIR)
CFLAGS_LIB			= -lft -L $(LIBFT_DIR)

INCLUDE_DIR			= include
SRC_DIR				= src
OBJ_DIR				= obj
LIB_DIR				= lib
LIBFT_DIR			= lib/libft

SRC_FILES			= $(shell find src/ -type f -name '*.c')
# SRC_FILES			= $(foreach filename,$(FILENAMES),$(SRC_DIR)/$(filename).c)
OBJ_FILES			= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
MAIN				= philosophers.c
VALGRIND			= valgrind --leak-check=full --show-leak-kinds=all
VALGRIND			+= --track-origins=yes --quiet --tool=memcheck

HELGRIND			= valgrind --tool=helgrind

# ********** RULES ********** #

all:				$(NAME)

$(NAME):			$(OBJ_DIR) $(OBJ_FILES) 
					$(MAKE) -C $(LIBFT_DIR)
					$(CC) $(MAIN) $(OBJ_FILES) $(CFLAGS) $(CFLAGS_LIB) \
						-o $(NAME)

$(OBJ_DIR):
					mkdir -p $@

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c
					mkdir -p "$(@D)"
					$(CC) -c $< $(CFLAGS) -o $@

clean:
					echo $(CLEANING_MSG)
					rm -rf $(OBJ_DIR)
					$(MAKE) -C $(LIBFT_DIR) clean

fclean:				clean
					rm -f $(NAME)
					$(MAKE) -C $(LIBFT_DIR) fclean

bonus:				all

re:					fclean all

re_bonus:			fclean bonus

# Add -g flag and change output to debug
setup_debug:
					$(eval NAME=debug)
					$(eval CFLAGS+=-g)

# Compile with -g flag and output the 'debug' file
debug:				clean setup_debug all

run:				all
					./$(NAME)

runv:				all
					@$(VALGRIND) ./$(NAME)

runh:				all
					@$(HELGRIND) ./$(NAME)

test:				all
					./tests/tests.sh

norm:
					norminette | grep Error

.PHONY:	all run clean fclean re re_bonus debug setup_debug norm

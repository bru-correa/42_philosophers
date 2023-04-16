NAME					= philo
CC						= gcc
CFLAGS				= -Wall -Wextra -Werror -I$(LIBFT_DIR) -I$(INCLUDE_DIR) -pthread
CFLAGS_LIB		= -lft -L $(LIBFT_DIR)

INCLUDE_DIR		= include
SRC_DIR				= src
OBJ_DIR				= obj
LIB_DIR				= lib
LIBFT_DIR			= lib/libft

FILENAMES			= create_philos create_simulation destroy_simulation forks
FILENAMES			+= handle_time log meals philo_actions routine run_simulation
FILENAMES			+= stop watch_philos
SRC_FILES			= $(foreach filename,$(FILENAMES),$(SRC_DIR)/$(filename).c)
OBJ_FILES			= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
MAIN					= philosophers.c
VALGRIND			= valgrind --leak-check=full --show-leak-kinds=all
VALGRIND			+= --track-origins=yes --quiet --tool=memcheck

HELGRIND			= valgrind --tool=helgrind --quiet --ignore-thread-creation=yes

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
					@./$(NAME) 5 400 100 100 10

runv:				all
					@$(VALGRIND) ./$(NAME) 5 400 100 100 10

runh:				all
					@$(HELGRIND) ./$(NAME) 5 400 100 100 10

test:				all
					@./tests/tests.sh

norm:
					@norminette | grep Error

.PHONY:	all run clean fclean re re_bonus debug setup_debug norm

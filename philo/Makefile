NAME				= philo
CC					= gcc
CFLAGS				= -Wall -Wextra -Werror -I$(INCLUDE_DIR) -pthread

INCLUDE_DIR			= include
SRC_DIR				= src
OBJ_DIR				= obj

FILENAMES			= create_philos create_simulation destroy_simulation forks
FILENAMES			+= handle_time log meals philo_actions routine run_simulation
FILENAMES			+= stop watch_philos is_number ft_atoi
SRC_FILES			= $(foreach filename,$(FILENAMES),$(SRC_DIR)/$(filename).c)
OBJ_FILES			= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
MAIN				= philosophers.c

# ********** RULES ********** #

all:				$(NAME)

$(NAME):			$(OBJ_DIR) $(OBJ_FILES) 
					$(CC) $(MAIN) $(OBJ_FILES) $(CFLAGS) -o $(NAME)

$(OBJ_DIR):
					mkdir -p $@

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c
					mkdir -p "$(@D)"
					$(CC) -c $< $(CFLAGS) -o $@

clean:
					rm -rf $(OBJ_DIR)

fclean:				clean
					rm -f $(NAME)

bonus:				all

re:					fclean all

re_bonus:			fclean bonus

# Add -g flag and change output to debug
setup_debug:
					$(eval NAME=debug)
					$(eval CFLAGS+=-g)

# Compile with -g flag and output the 'debug' file
debug:				clean setup_debug all

.PHONY:	all run clean fclean re re_bonus debug setup_debug

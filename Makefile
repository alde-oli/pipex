NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src
LIBFT_DIR = ./mini_libft
INCLUDE_DIR = ./include
OBJ_DIR = ./obj

INCLUDES = -I$(INCLUDE_DIR)

SRC = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(LIBFT_DIR)/*.c)
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $@

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
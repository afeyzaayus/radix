NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = 	check.c \
		push_swap.c \
		push.c \
		rotate.c \
		sorting.c \
		stack_utils.c \
		stack.c \
		swap.c \
		utils.c \
		radix.c

OBJ = $(SRC:.c=.o)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a


all: $(NAME)

$(NAME): $(OBJ)
		make -C $(LIBFT_PATH)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
		make -C $(LIBFT_PATH) clean
		rm -rf $(OBJ)

fclean: clean
		make -C $(LIBFT_PATH) fclean
		rm -rf $(OBJ)
		rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re




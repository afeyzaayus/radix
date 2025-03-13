NAME = push_swap

CC = cc

SRC = 	check.c \
		push_swap.c \
		push.c \
		rotate.c \
		sorting.c \
		stack_utils.c \
		stack.c \
		swap.c \
		utils.c \
		./getnl/get_next_line.c \
		./getnl/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(OBJ)
		make -C $(LIBFT_PATH)
		$(CC) $(OBJ) $(LIBFT) -o $(NAME)

clean:
		make -C $(LIBFT_PATH) clean
		rm -rf $(OBJ)

fclean: clean
		make -C $(LIBFT_PATH) fclean
		rm -rf $(OBJ)
		rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re




NAME = so_long

MLX_DIR = mlx
LIBFT_DIR = libft
FT_PRINTF_DIR = ft_printf

CC = cc
CFLAGS =	-Wall -Wextra -Werror \
			-I$(MLX_DIR) \
			-I$(LIBFT_DIR) \
			-I$(FT_PRINTF_DIR)
LFLAGS =	-L$(MLX_DIR) \
			-L$(LIBFT_DIR) \
			-L$(FT_PRINTF_DIR) \
			-lmlx -lXext -lX11 -lm -lz -lft -lftprintf

SRCS = src/main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

$(NAME): $(MLX_DIR) $(LIBFT_DIR) $(FT_PRINTF_DIR) $(OBJS)
	$(CC) -o $@ $(OBJS) $(LFLAGS)

$(MLX_DIR):
	$(MAKE) -C $(MLX_DIR)

$(LIBFT_DIR):
	$(MAKE) -C $(LIBFT_DIR)
_
$(FT_PRINTF_DIR):
	$(MAKE) -C $(FT_PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

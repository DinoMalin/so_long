NAME = so_long

MLX_DIR = mlx
LIBFT_DIR = libft
FT_PRINTF_DIR = ft_printf

MLX = $(MLX_DIR)/libmlx.a
LIBFT = $(MLX_DIR)/libft.a
FT_PRINTF = $(MLX_DIR)/libftprintf.a

CC = cc
CFLAGS =	-Wall -Wextra -Werror \
			-I$(MLX_DIR) \
			-I$(LIBFT_DIR) \
			-I$(FT_PRINTF_DIR)/include
LFLAGS =	-L$(MLX_DIR) \
			-L$(LIBFT_DIR) \
			-L$(FT_PRINTF_DIR) \
			-lmlx -lXext -lX11 -lm -lz -lft -lftprintf

FILES = main parse map check_map

SRCS = $(addprefix src/, $(addsuffix .c, $(FILES)))
OBJS = $(addprefix src/, $(addsuffix .o, $(FILES)))

all: $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

$(NAME): $(MLX) $(LIBFT) $(FT_PRINTF) $(OBJS)
	$(CC) -o $@ $(OBJS) $(LFLAGS)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

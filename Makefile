NAME = so_long

LIBFT = lib/libft.a

CC = cc

CFLAGS =	-Wall -Wextra -Werror -g \
			-Iinclude

LFLAGS =	-Llib \
			-lmlx_Linux -lXext -lX11 -lm -lz -lft

FILES = main parse update_map check_map move find_path init init_sprites end animation lore pteras handle_multiple_maps

OBJ_DIR = obj/
SRCS = $(addprefix src/, $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

all: $(NAME)

clean :
	rm -rf $(OBJ_DIR)
	make fclean -C lib

fclean : clean
	rm -rf $(NAME)
	make fclean -C lib

re: fclean all

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT)
	$(CC) -o $@ $(OBJS) $(LFLAGS)

$(LIBFT):
	make -C lib

$(OBJ_DIR):
	mkdir $@

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re

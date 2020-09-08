NAME = cub3D

# LIBFT = ./libft/libft.a

CC = gcc
INCS = -I./includes -I./libft -I./mlx
INCLIB = -Lmlx -lmlx -framework OpenGL -framework Appkit -Llibft -lft
CFLAGS = -Wall -Werror -Wextra $(INCS)
LIBFT = ./libft

SRCS =  ./src/get_next_line.c \
		./src/main.c \
		./src/init.c \
		./src/error.c \
		./src/parse_cub.c \
		./src/parse_element.c \
		./src/parse_map.c \
		./src/check_map.c \
		./src/check_element.c \
		./src/set_sprite.c \
		./src/set_texture.c \
		./src/main_loop.c \
		./src/raycasting.c \
		./src/key_handling.c \
		./src/draw.c \
		./src/bmp.c \
		./src/utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(CC) -g $(CFLAGS) $(INCS) -o $(NAME) $(OBJS) $(INCLIB)

clean:
	$(MAKE) -C $(LIBFT) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm -f $(OBJS)
	rm -f $(NAME)

re: fclean all

.PHONY: test bonus all clean fclean re
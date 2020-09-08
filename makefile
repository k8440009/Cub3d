NAME = cub3D

CC = gcc
INCS = -I./includes -I./libft -I./mlx
INCLIB = -Lmlx -lmlx -framework OpenGL -framework Appkit -Llibft -lft
CFLAGS = -Wall -Werror -Wextra $(INCS)
LIBFT = ./libft

SRCS =  ./src/get_next_line.c \
		./src/main.c \
		./src/main_loop.c \
		./src/init_info.c \
		./src/init_element.c \
		./src/init_map.c \
		./src/init_ray.c \
		./src/parse_cub.c \
		./src/parse_element.c \
		./src/check_element.c \
		./src/parse_map.c \
		./src/check_map.c \
		./src/set_sprite.c \
		./src/set_texture.c \
		./src/raycasting.c \
		./src/sort_sprite.c \
		./src/draw.c \
		./src/key_handling.c \
		./src/bmp.c \
		./src/map_utils.c \
		./src/utils.c \
		./src/free.c \
		./src/error.c

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


.PHONY: all clean fclean re
NAME = cub3D

CC = gcc
INCS = -I./includes -I./libft -I./mlx
INCLIB = -Lmlx -lmlx -framework OpenGL -framework Appkit -Llibft -lft
CFLAGS = -Wall -Werror -Wextra $(INCS)
LIBFT = ./libft
MLX = ./mlx
MLX_LIB = libmlx.a
BMP = screenshot.bmp

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

$(NAME): $(MLX_LIB) $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(CC) -g $(CFLAGS) $(INCS) -o $(NAME) $(OBJS) $(INCLIB)

$(MLX_LIB) :
	make all -C $(MLX)

clean:
	$(MAKE) clean -C $(LIBFT)
	$(MAKE) clean -C $(MLX)

fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	rm -rf $(OBJS)
	rm -rf $(NAME)
	rm -rf $(BMP)

re: fclean all


.PHONY: all clean fclean re
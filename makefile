NAME = cub3D

LIBFT = ./libft/libft.a

CC = gcc
INCS = -I./includes -I./libft -I./mlx
INCLIB = -Lmlx -lmlx -framework OpenGL -framework Appkit -Llibft -lft
# CFLAGS = -Wall -Werror -Wextra $(INCS)
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
		./src/control_player.c \
		./src/utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(INCS) -o $(NAME) $(OBJS) $(INCLIB)

clean:
	$(MAKE) -C $(LIBFT) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: test bonus all clean fclean re
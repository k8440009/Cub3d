# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/11 07:10:57 by sungslee          #+#    #+#              #
#    Updated: 2020/08/14 20:53:45 by sungslee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc
LIBFT = ./libs/libft
INCS = -I ./includes -I ./libs/libft -I ./libs/minilibx
INCLIB = -lmlx -framework OpenGL -framework Appkit -L ./libs/libft -lft
CFLAGS = -Wall -Werror -Wextra $(INCS)

SRCS =  ./src/get_next_line.c \
		./src/main.c \
		./src/error.c \
		./src/utils.c \
		./src/parse_cub

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CLAGS) $(INCS) -g -o $(NAME) $(OBJS) $(INCLIB)

clean :
	$(MAKE) -C $(LIBFT) clean
	rm -f $(OBJS)
fclean : clean
	$(MAKE) -C $(LIBFT) fclean
	rm -f $(NAME)

re : fclean all
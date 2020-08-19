/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 16:02:20 by sungslee          #+#    #+#             */
/*   Updated: 2020/08/19 03:52:19 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/minilibx/mlx.h"
# include "../libs/libft/libft.h"
# include "get_next_line.h"
# include <math.h>
# include <fcntl.h>

# define PI 3.1415926535897

# define ELEMENT_ERROR 1
# define MAP_ERROR 2

# define NORTH 0
# define EAST 1
# define SOUTH 2
# define WEST 3
# define SPRITE 4

# define FLOOR 1
# define CEILING 2
/*
**	check element
*/
# define NUMBER 1

typedef struct		s_info
{
	int			fd;
	int			width;
	int			height;
	char		*north_texture_path;
	char		*south_texture_path;
	char		*west_texture_path;
	char		*east_texture_path;
	char		*sprite_texture_path;
	int			floor_color;
	int			ceiling_color;
}					t_info;
/*
**	parse_cub
*/
int			parse_cub(t_info *info, char *path);
/*
** error
*/
// int			print_error(int	error_code, t_info *info);
int			print_error(char *message, t_info *info);
/*
**	utils
*/
void			free_two_pointer(char **str);
#endif

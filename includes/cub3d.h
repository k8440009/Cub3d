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

typedef struct		s_sprite
{
	double			y;
	double			x;
	double			distance;
}					t_sprite;

typedef struct		s_player
{
	double			y;
	double			x;
}					t_player;

typedef struct		s_info
{
	void		*mlx;
	void		*win;
	t_player	player;
	t_sprite	*sprite;
	int			fd;
	int			win_width;
	int			win_height;
	int			map_width;
	int			map_height;
	char		**map;
	char		*north_texture_path;
	char		*south_texture_path;
	char		*west_texture_path;
	char		*east_texture_path;
	char		*sprite_texture_path;
	int			floor_color;
	int			ceiling_color;
	int			count_sprite;
	int			dir;
}					t_info;
/*
**	parse_cub
*/
int			parse_cub(t_info *info, char *path);
/*
**	parse_map
*/
int			check_valid_map(t_info *info);
int			init_direction(t_info *info, int y, int x, int *dir_count);
int			fill_map(t_info *info, t_list *lst);
int			get_max_line_size(t_list *lst);
int			init_map(t_info *info, t_list *lst);
int			parse_map(t_info *info, t_list *lst);
int			read_map(t_info *info, char *line);
/*
**	parse_sprite
*/
int			set_sprite(t_info *info);
/*
** error
*/
// int			print_error(int	error_code, t_info *info);
int			print_error(char *message, t_info *info);
/*
**	utils
*/
void		free_two_pointer(char **str);
int			is_map_arg(int c);
/*
**	check_element
*/
int			check_info(t_info *info);
/*
**	check_map
*/
int			check_map_left(t_info *info, int y, int x);
int			check_map_right(t_info *info, int y, int x);
int			check_map_bottom(t_info *info, int y);
int			check_map_middle(t_info *info, int y, int x);
int			check_map_top(t_info *info);
#endif

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

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "get_next_line.h"
# include <math.h>
# include <fcntl.h>
// # include <stdio.h>
# define PI 3.1415926535897

# define TRUE '1'
# define FALSE '0'

# define ELEMENT_ERROR 1
# define MAP_ERROR 2

# define NORTH 0
# define EAST 1
# define SOUTH 2
# define WEST 3
# define SPRITE 4

# define FLOOR 1
# define CEILING 2

# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64
/*
**	check element
*/
# define NUMBER 1

typedef struct		s_state
{
	int 			dr[4];
	int				dc[4];
	int				r;
	int				c;
	int				flag;
}					t_state;

typedef struct		s_img
{
	void			*img;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
	int				width;
	int				height;
}					t_img;

typedef struct		s_sprite
{
	double			y;
	double			x;
	double			distance;
}					t_sprite;

typedef struct		s_player
{
	int				start_r;
	int				start_c;
	double			x;
	double			y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			move_speed;
	double			rotate_speed;
}					t_player;

typedef struct		s_info
{
	void		*mlx;
	void		*win;
	t_player	player;
	t_sprite	*sprite;
	t_img		img;
	int			fd;
	int			win_width;
	int			win_height;
	int			map_width;
	int			map_height;
	char		**map;
	char		**visited;
	char		*north_texture_path;
	char		*south_texture_path;
	char		*west_texture_path;
	char		*east_texture_path;
	char		*sprite_texture_path;
	int			floor_color;
	int			ceiling_color;
	int			count_sprite;
	int			dir;
	int			**texture;
}					t_info;
/*
**	init.c
*/
void		init_info(t_info *info);
void		init_player(t_player *player);
void		init_player_direction(t_info *info);
int			init_direction(t_info *info, int y, int x, int *dir_count);
int			init_map(t_info *info, t_list *lst);
int			init_texture(t_info *info);
/*
**	parse_cub
*/
int			pre_process_cub(t_info *info, char *path);
int			parse_element(t_info *info, char *line);
int			pre_process_map(t_info *info, char *line);
/*
**	parse_element.c
*/
int			parse_element_line(t_info *info, char *line);
int			get_color(t_info *info, char *line, int type);
int			get_texture(t_info *info, char *line, int type);
int			get_screen_size(t_info *info, char *line);
/*
**	parse_map.c
*/
int			parse_map(t_info *info, t_list *lst);
int			set_map_data(t_info *info, t_list *lst);
/*
**	check_map
*/
int			check_valid_map(t_info *info);
int			init_visited(t_info *info);
int			valid_map(t_info *info);
void		dfs(t_info *info, t_state *state, int r, int c);
/*
**	check_element
*/
int			check_info(t_info *info);
/*
**	move_player
*/
void		rotate_player(t_player *player, double rotate_speed);
/*
**	set_sprite
*/
int			set_sprite(t_info *info);
int			set_pos_sprite(t_info *info, int idx, int r, int c);
/*
**	set_texture
*/
void		set_texture(t_info *info);
void		load_image(t_info *info, int *texture, char *path, t_img *img);
/*
**	utils
*/
void		free_two_pointer(char **str);
void		ft_free(void *s);
int			is_map_arg(int c);
int			get_max_line_size(t_list *lst);
/*
** error
*/
// int			print_error(int	error_code, t_info *info);
int			print_error(char *message, t_info *info);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 19:07:55 by sungslee          #+#    #+#             */
/*   Updated: 2020/08/14 20:16:08 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/minilibx/mlx.h"
# include "../libs/libft/libft.h"
# include "get_next_line.h"
# include <math.h>
# include <fcntl.h>

typedef struct		s_sprite_ray
{
	double		x;
	double		y;
	double		inversion_detection;
	double		transform_x;
	double		transform_y;
	int			screen_x;
	int			v_move_screen;
	int			height;
	int			width;
	int			draw_start_x;
	int			draw_start_y;
	int			draw_end_x;
	int			draw_end_y;
	int			texture_x;
	int			texture_y;
}					t_sprite_ray;

typedef struct		s_sprite
{
	double			x;
	double			y;
	double			distance;
	t_sprite_ray	sprite_ray;
}					t_sprite;

typedef struct		s_player_ray
{
	double			camera_x;
	double			dir_x;
	double			dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			pep_wall_dist;
	double			wall_x;
	double			step;
	double			texture_pos;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				hit;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				texture_num;
	int				texture_x;
	int				texture_y;
}					t_player_ray;

typedef struct		s_player
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		rotate_speed;
}					t_player;

typedef struct		s_info
{
	void		*mlx;
	void		*win;
	t_player	player;
	t_sprite	*sprite;
	int			**buf;
	double		*z_buffer;
	int			**texture;
	int			fd;
	int			width;
	int			height;
	int			map_width;
	int			map_height;
	int			**map;
	char		*north_texture_path;
	char		*south_texture_path;
	char		*west_texture_path;
	char		*east_texture_path;
	char		*sprite_texture_path;
	int			floor_color;
	int			ceiling_color;
	int			dir;
	int			num_sprite;
}					t_info;

void		init_player(t_player *player);
int			parse_cub(t_info *info, char *path);

int		exit_error(t_info *info);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 03:55:35 by sungslee          #+#    #+#             */
/*   Updated: 2020/09/09 03:55:37 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			init_texture(t_info *info)
{
	int		r;

	if (!(info->texture = (int **)ft_calloc(5, sizeof(int *))))
		return (0);
	r = -1;
	while (++r < 5)
	{
		if (!(info->texture[r] = (int *)
		ft_calloc(TEXTURE_HEIGHT * TEXTURE_WIDTH, sizeof(int))))
			return (0);
	}
	return (1);
}

void		init_player_direction(t_info *info)
{
	int		rotate;

	rotate = 0;
	if (info->dir == NORTH)
		rotate = 270;
	else if (info->dir == EAST)
		rotate = 0;
	else if (info->dir == SOUTH)
		rotate = 90;
	else if (info->dir == WEST)
		rotate = 180;
	rotate_player(&info->player, rotate * (PI / 180));
}

int			init_buffer(t_info *info)
{
	int		r;

	if (!(info->buf = ft_calloc(info->win_height, sizeof(int **))))
		return (print_error("init_buffer calloc error", info));
	r = -1;
	while (++r < info->win_height)
	{
		if (!(info->buf[r] = ft_calloc(info->win_width, sizeof(int *))))
			return (print_error("init_buffer col error", info));
	}
	if (!(info->z_buf = ft_calloc(info->win_width, sizeof(double *))))
		return (print_error("init_buffer z_buf error", info));
	return (1);
}

void		init_player(t_player *player)
{
	player->x = 2;
	player->y = 5;
	player->dir_x = -1.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.66;
	player->move_speed = 0.1;
	player->rot_speed = 0.1;
}

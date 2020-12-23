/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 03:44:45 by sungslee          #+#    #+#             */
/*   Updated: 2020/09/09 03:44:48 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		draw_texture(t_info *info)
{
	int		y;
	int		x;

	y = -1;
	while (++y < info->win_height)
	{
		x = -1;
		while (++x < info->win_width)
			info->img.data[info->win_width * y + x] = info->buf[y][x];
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

void		get_wall_color(t_info *info, t_ray *ray, int x)
{
	int		color;
	int		y;

	ray->step = 1.0 * TEXTURE_HEIGHT / ray->line_height;
	ray->texture_pos = (ray->draw_start - info->win_height / 2 +
					ray->line_height / 2) * ray->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		ray->texture_y = (int)ray->texture_pos & (TEXTURE_HEIGHT - 1);
		ray->texture_pos += ray->step;
		color = info->texture[ray->side]
		[TEXTURE_HEIGHT * ray->texture_y + ray->texture_x];
		info->buf[y][x] = color;
		y++;
	}
}

void		get_wall_texture(t_player *player, t_ray *ray)
{
	if (ray->side <= 1)
		ray->wall_x = player->y + ray->perp_wall_dist * ray->dir_y;
	else
		ray->wall_x = player->x + ray->perp_wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->texture_x = (int)(ray->wall_x * (double)TEXTURE_WIDTH);
	if (ray->side == 1 || ray->side == 2)
		ray->texture_x = TEXTURE_WIDTH - ray->texture_x - 1;
}

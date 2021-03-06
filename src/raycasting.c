/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 04:13:18 by sungslee          #+#    #+#             */
/*   Updated: 2020/09/09 04:13:20 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		calculate_wall_height(t_info *info, t_ray *ray)
{
	ray->line_height = (int)(info->win_height / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + info->win_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + info->win_height / 2;
	if (ray->draw_end >= info->win_height)
		ray->draw_end = info->win_height - 1;
}

void		calculate_wall_distance(t_player *player, t_ray *ray)
{
	if (ray->side <= 1)
		ray->perp_wall_dist = (ray->map_x - player->x + (1 - ray->step_x) / 2)
		/ ray->dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - player->y + (1 - ray->step_y) / 2)
		/ ray->dir_y;
}

void		perform_dda(t_info *info, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = (ray->step_x == -1) ? 0 : 1;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = (ray->step_y == -1) ? 2 : 3;
		}
		if (info->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

void		calculate_step_and_side_dist(t_player *player, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player->x) * ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->y) * ray->delta_dist_y;
	}
}

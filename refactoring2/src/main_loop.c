/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 04:03:40 by sungslee          #+#    #+#             */
/*   Updated: 2020/09/09 04:03:42 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		sprite_raycasting(t_info *info, t_player *player)
{
	int	i;
	int	stripe;

	sort_sprite(info, player);
	i = -1;
	while (++i < info->count_sprite)
	{
		translate_sprite(info, player, &info->s_ray, i);
		calculate_sprite_height(info, &info->s_ray);
		calculate_sprite_width(info, &info->s_ray);
		stripe = info->s_ray.draw_start_x;
		while (stripe < info->s_ray.draw_end_x)
		{
			get_sprite_color(info, &info->s_ray, stripe);
			stripe++;
		}
	}
}

void		raycasting(t_info *info)
{
	int		x;

	cast_floor_ceiling(info);
	x = -1;
	while (++x < info->win_width)
	{
		init_ray(info, &info->player, &info->ray, x);
		calculate_step_and_side_dist(&info->player, &info->ray);
		perform_dda(info, &info->ray);
		calculate_wall_distance(&info->player, &info->ray);
		calculate_wall_height(info, &info->ray);
		get_wall_texture(&info->player, &info->ray);
		get_wall_color(info, &info->ray, x);
		info->z_buf[x] = info->ray.perp_wall_dist;
	}
}

int			main_loop(t_info *info)
{
	raycasting(info);
	sprite_raycasting(info, &info->player);
	draw_texture(info);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 03:55:06 by sungslee          #+#    #+#             */
/*   Updated: 2020/09/09 03:55:11 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		init_flag(t_flag *flag)
{
	flag->cnt = 0;
	flag->r = 0;
	flag->c = 0;
	flag->no = 0;
	flag->ea = 0;
	flag->so = 0;
	flag->we = 0;
	flag->s = 0;
	flag->f = 0;
	flag->c = 0;
}

void		init_info(t_info *info)
{
	info->win_width = 0;
	info->win_height = 0;
	info->map_width = 0;
	info->map_height = 0;
	info->map = NULL;
	info->visited = NULL;
	info->north_texture_path = NULL;
	info->south_texture_path = NULL;
	info->west_texture_path = NULL;
	info->east_texture_path = NULL;
	info->floor_color = 0;
	info->ceiling_color = 0;
	info->count_sprite = 0;
	info->sprite = NULL;
	info->buf = NULL;
	info->z_buf = NULL;
	init_flag(&info->flag);
}

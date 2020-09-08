/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 04:11:56 by sungslee          #+#    #+#             */
/*   Updated: 2020/09/09 04:11:57 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			get_rgb(char **rgb)
{
	int		i;
	int		tmp;
	int		color;

	color = 0;
	i = 0;
	while (rgb[i])
	{
		tmp = ft_atoi(rgb[i]);
		if (tmp < 0 || tmp > 255)
			return (-1);
		color *= 256;
		color += tmp;
		i++;
	}
	return (color);
}

void		fill_flag(t_info *info, int type)
{
	if (type == NORTH)
		info->flag.no = 1;
	else if (type == EAST)
		info->flag.ea = 1;
	else if (type == SOUTH)
		info->flag.so = 1;
	else if (type == WEST)
		info->flag.we = 1;
	else if (type == SPRITE)
		info->flag.s = 1;
	else if (type == FLOOR)
		info->flag.f = 1;
	else if (type == CEILING)
		info->flag.c = 1;
	info->flag.cnt += 1;
}

int			get_texture(t_info *info, char *line, int type)
{
	if (!info->flag.no && type == NORTH)
		info->north_texture_path = ft_strdup(line);
	else if (!info->flag.ea && type == EAST)
		info->east_texture_path = ft_strdup(line);
	else if (!info->flag.so && type == SOUTH)
		info->south_texture_path = ft_strdup(line);
	else if (!info->flag.we && type == WEST)
		info->west_texture_path = ft_strdup(line);
	else if (!info->flag.s && type == SPRITE)
		info->sprite_texture_path = ft_strdup(line);
	else
		return (print_error("get_texture flag or type error", info));
	fill_flag(info, type);
	return (1);
}

int			get_color(t_info *info, char *line, int type)
{
	char	**rgb;
	int		color;

	if (!(rgb = ft_split(line, ',')) || !check_split_size(rgb, 3))
		return (print_error("get color split error\n", info));
	if (!check_str_digit(rgb[0]) || !check_str_digit(rgb[1]) ||
		!check_str_digit(rgb[2]))
		return (print_error("get color str digit error\n", info));
	if ((color = get_rgb(rgb)) == -1)
		return (print_error("get color str digit error\n", info));
	free_two_arr(rgb);
	if (!info->flag.f && type == FLOOR)
		info->floor_color = color;
	else if (!info->flag.c && type == CEILING)
		info->ceiling_color = color;
	else
		return (print_error("duplicaet rgb color error\n", info));
	fill_flag(info, type);
	return (1);
}

int			get_screen_size(t_info *info, char *line)
{
	char	**data;

	if (info->flag.r == 1)
		return (print_error("duplicate window size error", info));
	if (!(data = ft_split(line, ' ')) || !check_split_size(data, 2))
		return (print_error("split size error", info));
	if (!check_str_digit(data[0]) || !check_str_digit(data[1]))
		return (print_error("split  data error", info));
	info->win_width = ft_atoi(data[0]);
	info->win_height = ft_atoi(data[1]);
	info->flag.cnt += 1;
	info->flag.r = 1;
	free_two_arr(data);
	return (1);
}

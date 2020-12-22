#include "../includes/cub3d.h"

int			getRgb(char **rgb)
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

void		fillFlag(t_gameInfo *info, int type)
{
	/*
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
	*/
}

int			getColor(t_gameInfo *info, char *line, int type)
{
	char	**rgb;
	int		color;

	rgb = ft_split(line, ',');
	freeTwoArr(rgb);

	/*
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
	*/
	return (1);
}

int			getTexture(t_gameInfo *info, char *line, int type)
{
	t_mapInfo *mapInfo = info->map_info;
	if (type == NORTH)
		mapInfo->northTexturePath = ft_strdup(line);
	else if (type == EAST)
		mapInfo->eastTexturePath = ft_strdup(line);
	else if (type == SOUTH)
		mapInfo->southTexturePath = ft_strdup(line);
	else if (type == WEST)
		mapInfo->westTexturePath = ft_strdup(line);
	else if (type == SPRITE)
		mapInfo->spriteTexturePath = ft_strdup(line);
	/*
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
	*/
	return (1);
}


int			getScreenSize(t_gameInfo *info, char *line)
{
	char	**data;
	data = ft_split(line, ' ');
	info->win_width = ft_atoi(data[0]);
	info->win_height = ft_atoi(data[1]);

	freeTwoPoint(data);
	/*
	if (info->flag.r == 1)
		return (print_error("duplicate window size error", info));
	if (!(data = ft_split(line, ' ')) || !check_split_size(data, 2))
		return (print_error("split size error", info));
	if (!check_str_digit(data[0]) || !check_str_digit(data[1]))
		return (print_error("split  data error", info));
	info->win_width = ft_atoi(data[0]);
	info->win_height = ft_atoi(data[1]);
	//info->flag.cnt += 1;
	//info->flag.r = 1;
	//free_two_arr(data);
	*/
	return (1);
}
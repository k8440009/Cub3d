#include "../includes/cub3d.h"

int			check_str_digit(char *data)
{
	int		idx;

	idx = -1;
	while (data[++idx])
	{
		if (!ft_isdigit(data[idx]))
			return (0);
	}
	return (1);
}

int			check_split_size(char **data, int cur_size)
{
	int		size = 0;

	while (*data)
	{
		size++;
		data++;
	}
	if (cur_size != size)
		return (0);
	return (1);
}

int			get_screen_size(t_info *info, char *line)
{
	char	**data;

	if (!(data = ft_split(line, ' ')))
		return (print_error("split error", info));
	if (!data || !check_split_size(data, 2))
		return (print_error("split size error", info));
	if (!check_str_digit(data[0]) || !check_str_digit(data[1]))
		return (print_error("split data error", info));
	info->win_width = ft_atoi(data[0]);
	info->win_height = ft_atoi(data[1]);
	free_two_pointer(data);
	if (info->win_width <= 0 || info->win_height <= 0)
		return (print_error("get_screen_size error (win_size)\n", info));
	info->flag_cnt += 1;
	return (1);
}

int			get_texture(t_info *info, char *line, int type)
{
	if (type == NORTH)
		info->north_texture_path = ft_strdup(line);
	else if (type == EAST)
		info->east_texture_path = ft_strdup(line);
	else if (type == SOUTH)
		info->south_texture_path = ft_strdup(line);
	else if (type == WEST)
		info->west_texture_path = ft_strdup(line);
	else if (type == SPRITE)
		info->sprite_texture_path = ft_strdup(line);
	else
		return (print_error("texture error", info));
	info->flag_cnt += 1;
	return (1);
}

int			get_color(t_info *info, char *line, int type)
{
	char	**rgb;
	int		color;
	int		i;

	if (!(rgb = ft_split(line, ',')))
		return (print_error("get color error1\n", info));
	if (!rgb || !check_split_size(rgb, 3))
		return (print_error("get color split size error\n", info));
	if (!check_str_digit(rgb[0]) || !check_str_digit(rgb[1]) || !check_str_digit(rgb[2]))
		return (print_error("get color str digit error\n", info));
	color = 0;
	i = 0;
	while (rgb[i])
	{
		color *= 256;
		color += ft_atoi(rgb[i]);
		i++;
	}
	free_two_pointer(rgb);
	if (type == FLOOR)
		info->floor_color = color;
	else if (type == CEILING)
		info->ceiling_color = color;
	info->flag_cnt += 1;
	return (1);
}

int			parse_element_line(t_info *info, char *line)
{
	if (ft_strncmp(line, "R ", 2) == 0)
		return (get_screen_size(info, line + 2));
	else if (ft_strncmp(line, "NO ", 3) == 0)
		return (get_texture(info, line + 3, NORTH));
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (get_texture(info, line + 3, SOUTH));
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (get_texture(info, line + 3, WEST));
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (get_texture(info, line + 3, EAST));
	else if (ft_strncmp(line, "S ", 2) == 0)
		return (get_texture(info, line + 2, SPRITE));
	else if (ft_strncmp(line, "F ", 2) == 0)
		return (get_color(info, line + 2, FLOOR));
	else if (ft_strncmp(line, "C ", 2) == 0)
		return (get_color(info, line + 2, CEILING));
	else if (line[0] == '\0')
		return (1);
	return (0);
}
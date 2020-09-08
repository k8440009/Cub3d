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

int			check_flag(t_info *info)
{
	if (info->flag.cnt != 8)
		return (print_error("element flag cnt error", info));
	if (!info->flag.r || !info->flag.no || !info->flag.so ||
		!info->flag.we || !info->flag.ea || !info->flag.s ||
		!info->flag.s || !info->flag.f || !info->flag.c)
		return (print_error("element null error", info));
	return (1);
}

int			check_map(t_info *info)
{
	if (info->map_width <= 0 || info->map_height <= 0)
		return (print_error("check_map size error", info));
	return (1);
}

int			check_element(t_info *info)
{
	if (!check_flag(info))
		return (print_error("element flag error", info));
	if (info->win_width <= 0 || info->win_height <= 0 || info->floor_color < 0 || info->ceiling_color < 0)
		return (print_error("element size error", info));
	if (!info->north_texture_path || !info->east_texture_path ||
		!info->west_texture_path || !info->south_texture_path ||
		!info->sprite_texture_path || !info->floor_color)
		return (print_error("element texture path error", info));
	return (1);
}
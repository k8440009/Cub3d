#include "../includes/cub3d.h"

int			check_info(t_info *info)
{
	if (info->win_width <= 0 || info->win_height <= 0
		|| info->map_width <= 0 || info->map_height <= 0
		|| info->floor_color <= 0 || info->ceiling_color <= 0)
		return (print_error("check_info error1", info));
	else if (!info->north_texture_path || !info->east_texture_path
		|| !info->west_texture_path || !info->south_texture_path
		|| !info->sprite_texture_path || !info->floor_color)
		return (print_error("check_info error2", info));
	return (1);
}
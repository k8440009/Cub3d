#include "../includes/cub3d.h"

int			check_map(t_info *info)
{
	if (info->map_width <= 0 || info->map_height <= 0)
		return (print_error("check_map size error", info));
	return (1);
}

int			check_element(t_info *info)
{
	if (info->flag_cnt != 8)
		return (print_error("check_element flag cnt", info));
	if (info->win_width <= 0 || info->win_height <= 0 || info->floor_color <= 0 || info->ceiling_color <= 0)
		return (print_error("check_element size error", info));
	if (!info->north_texture_path || !info->east_texture_path || !info->west_texture_path || !info->south_texture_path || !info->sprite_texture_path || !info->floor_color)
		return (print_error("check_element texture path error", info));
	return (1);
}
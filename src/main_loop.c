#include "../includes/cub3d.h"

int			main_loop(t_info *info)
{
	raycasting(info);
	//sprite_raycasting(info, &info->player);
	draw_texture(info);
	return (0);
}
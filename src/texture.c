#include "../includes/cub3d.h"

void		cast_floor_ceiling(t_info *info)
{
	int		y;
	int		x;

	y = 0;
	while (y < info->height)
	{
		x = 0;
		while (x < info->width)
		{
			if (y > info->height / 2)
				info->buf[y][x] = info->floor_color;
			else
				info->buf[y][x] = info->ceiling_color;
			x++;
		}
		y++;
	}
}
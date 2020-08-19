#include "../includes/cub3d.h"

int			set_pos_sprite(t_info *info, int i, int y, int x)
{
	info->sprite[i].y = 0.5f + y;
	info->sprite[i].x = 0.5f + x;
}

int			set_sprite(t_info *info)
{
	int		y;
	int		x;
	int		i;

	y = 0;
	i = 0;
	if (!(info->sprite = (t_sprite *)malloc(sizeof(t_sprite) * info->count_sprite)))
		return (print_error("set_sprite error", info));
	while (y < info->map_height)
	{
		x = 0;
		while (x < info->map_width)
		{
			if (info->map[y][x] == '2')
			{
				set_pos_sprite(info, i, y, x);
				i++;
			}
			x++;
		}
		y++;
	}
	return (1);
}
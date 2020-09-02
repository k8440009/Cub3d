#include "../includes/cub3d.h"

int			set_pos_sprite(t_info *info, int idx, int r, int c)
{
	info->sprite[idx].y = 0.5f + r;
	info->sprite[idx].x = 0.5f + c;
	return (1);
}

int			set_sprite(t_info *info)
{
	int		r;
	int		c;
	int		idx;

	if (!(info->sprite = (t_sprite *)calloc(info->count_sprite, sizeof(t_sprite))))
		return (print_error("set_sprite memory error", info));
	r = -1;
	while (++r < info->map_height)
	{
		c = -1;
		while (++c < info->map_width)
		{
			if (info->map[r][c] == '2')
			{
				set_pos_sprite(info, idx, r, c);
				idx++;
			}
		}
	}
	return (1);
}
#include "../includes/cub3d.h"

void		bubble_sort(t_info *info)
{
	int			i;
	int			j;
	int			max;
	t_sprite	temp;

	i = 0;
	while (i < info->count_sprite - 1)
	{
		max = i;
		j = i + 1;
		while (j < info->count_sprite)
		{
			if (info->sprite[j].distance > info->sprite[i].distance)
				max = j;
			j++;
		}
		if (i != max)
		{
			temp = info->sprite[i];
			info->sprite[i] = info->sprite[max];
			info->sprite[max] = temp;
		}
		i++;
	}
}

void		sort_sprite(t_info *info, t_player *player)
{
	int	i;

	i = -1;
	while (++i < info->count_sprite)
		info->sprite[i].distance = ((player->x - info->sprite[i].x) * (player->x - info->sprite[i].x) + (player->y - info->sprite[i].y) * (player->y - info->sprite[i].y));
	bubble_sort(info);
}
#include "cub3d.h"

void	init_player_direction(t_info *info)
{
	int	rot;
	int	direction;

	rot = 0;
	direction = info->dir;
	if (direction == 'N')
		rot = 270;
	else if (direction == 'S')
		rot = 90;
	else if (direction == 'E')
		rot = 0;
	else if (direction == 'W')
		rot = 180;
	rotate_player(&info->player, rot * (PI / 180));
}
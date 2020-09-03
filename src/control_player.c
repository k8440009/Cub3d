#include "../includes/cub3d.h"

/*
void	rotate_player(t_player *player, double rotate_speed)
{
	double		prev_dir_x;
	double		prev_plane_x;

	prev_dir_x = player->vec_dir_x;
	prev_plane_x = player->plane_x;
	player->vec_dir_x = player->vec_dir_x * cos(rotate_speed)
				- player->vec_dir_y * sin(rotate_speed);
	player->vec_dir_y = prev_dir_x * sin(rotate_speed)
				+ player->vec_dir_y * cos(rotate_speed);
	player->plane_x = player->plane_x * cos(rotate_speed)
				- player->plane_y * sin(rotate_speed);
	player->plane_y = prev_plane_x * sin(rotate_speed)
				+ player->plane_y * cos(rotate_speed);
}
*/
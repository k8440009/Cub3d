#include "../includes/cub3d.h"

void		init_player(t_player *player)
{
    player->x = 2;
    player->y = 5;
    player->dir_x = -1.0;
    player->dir_y = 0.0;
    player->plane_x = 0.0;
    player->plane_y = 0.66;
    player->move_speed = 0.05;
    player->rotate_speed = 0.05;
}

void		init_info(t_info *info)
{
	info->width = 0;
	info->height = 0;
	info->map_width = 0;
	info->map_height = 0;
	info->map = NULL;
	info->buf = NULL;
	info->z_buffer = NULL;
	info->north_texture_path = NULL;
	info->south_texture_path = NULL;
	info->west_texture_path = NULL;
	info->east_texture_path = NULL;
	info->sprite_texture_path = NULL;
	info->floor_color = 0;
	info->ceiling_color = 0;
	info->num_sprite = 0;
	info->sprite = NULL;
}
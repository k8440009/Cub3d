#include "../includes/cub3d.h"

void	init_ray(t_info *info, t_player *player, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)info->width - 1;
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->map_x = (int)player->x;
	ray->map_y = (int)player->y;
	ray->delta_dist_x = fabs(1 / ray->dir_x);
	ray->delta_dist_y = fabs(1 / ray->dir_y);
	ray->hit = 0;
}

void	calculate_step_direction()
{

}

void	perform_dda()
{

}

void	calculate_wall_distance()
{

}

void	calculate_wall_height()
{
	
}
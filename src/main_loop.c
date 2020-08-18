#include "../includes/cub3d.h"

void	raycasting(t_info *info)
{
	int		x;

	x = 0;
	cast_floor_ceiling(info);
	while (x < info->width)
	{
		
		x++;
	}
	
}

void	sprite_raycasting(t_info *info, t_player *player)
{
	int	i;
	int	stripe;

	sort_sprite(info, player);
	i = 0;
	while (i < info->num_sprite)
	{
		translate_sprite(info, player, &info->s_ray, i);
		calculate_sprite_height(info, &info->s_ray);
		calculate_sprite_width(info, &info->s_ray);
		stripe = info->s_ray.draw_start_x;
		while (stripe < info->s_ray.draw_end_x)
		{
			get_sprite_color(info, &info->s_ray, stripe);
			stripe++;
		}
		i++;
	}
}

int		main(t_info *info)
{
	raycasting(info);
	sprite_raycasting(info, &info->player);
	draw(info);
	return (0);
}
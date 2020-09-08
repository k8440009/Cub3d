#include "../includes/cub3d.h"

void		sprite_raycasting(t_info *info, t_player *player)
{
	int	i;
	int	stripe;

	sort_sprite(info, player);
	i = -1;
	while (++i < info->count_sprite)
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
	}
}


int			main_loop(t_info *info)
{
	raycasting(info);
	sprite_raycasting(info, &info->player);
	draw_texture(info);
	return (0);
}
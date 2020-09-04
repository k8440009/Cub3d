#include "../includes/cub3d.h"

void		get_sprite_color(t_info *info, t_sprite_ray *s_ray, int stripe)
{
	int	color;
	int	y;
	int	draw;

	s_ray->texture_x = (int)((256 * (stripe - (-s_ray->width / 2 + s_ray->screen_x)) * TEXTURE_WIDTH / s_ray->width) / 256);
	if (s_ray->transform_y > 0 && stripe > 0 && stripe < info->win_width && s_ray->transform_y < info->z_buf[stripe])
	{
		y = s_ray->draw_start_y;
		while (y < s_ray->draw_end_y)
		{
			draw = (y - s_ray->v_move_screen) * 256 - info->win_height * 128 + s_ray->height * 128;
			s_ray->texture_y = ((draw * TEXTURE_HEIGHT) / s_ray->height) / 256;
			color = info->texture[4][TEXTURE_WIDTH * s_ray->texture_y + s_ray->texture_x];
			if ((color & 0x00FFFFFF) != 0)
				info->buf[y][stripe] = color;
			y++;
		}
	}
}

void		calculate_sprite_height(t_info *info, t_sprite_ray *s_ray)
{
	int	v_div;

	v_div = 1;
	s_ray->height = (int)fabs((info->win_height / s_ray->transform_y) / v_div);
	s_ray->draw_start_y = -s_ray->height / 2 + info->win_height / 2 + s_ray->v_move_screen;
	if (s_ray->draw_start_y < 0)
		s_ray->draw_start_y = 0;
	s_ray->draw_end_y = s_ray->height / 2 + info->win_height / 2 + s_ray->v_move_screen;
	if (s_ray->draw_end_y >= info->win_height)
		s_ray->draw_end_y = info->win_height - 1;
}

void		calculate_sprite_width(t_info *info, t_sprite_ray *s_ray)
{
	int	u_div;

	u_div = 1;
	s_ray->width = (int)fabs((info->win_height / s_ray->transform_y) / u_div);
	s_ray->draw_start_x = -s_ray->width / 2 + s_ray->screen_x;
	if (s_ray->draw_start_x < 0)
		s_ray->draw_start_x = 0;
	s_ray->draw_end_x = s_ray->width / 2 + s_ray->screen_x;
	if (s_ray->draw_end_x >= info->win_width)
		s_ray->draw_end_x = info->win_width - 1;
}

void		translate_sprite(t_info *info, t_player *player, t_sprite_ray *s_ray, int i)
{
	double	v_mode;

	v_mode = 0.0;
	s_ray->x = info->sprite[i].x - player->x;
	s_ray->y = info->sprite[i].y - player->y;
	s_ray->inversion_detection = 1.0 / (player->plane_x * player->vec_dir_y - player->vec_dir_x * player->plane_y);
	s_ray->transform_x = s_ray->inversion_detection * (player->vec_dir_y * s_ray->x - player->vec_dir_x * s_ray->y);
	s_ray->transform_y = s_ray->inversion_detection * (-player->plane_y * s_ray->x + player->plane_x * s_ray->y);
	s_ray->screen_x = (int)((info->win_width / 2) * (1 + s_ray->transform_x / s_ray->transform_y));
	s_ray->v_move_screen = (int)(v_mode / s_ray->transform_y);
}

void		sort_sprite(t_info *info, t_player *player)
{
	int	i;

	i = -1;
	while (++i < info->count_sprite)
		info->sprite[i].distance = sqrt(((player->x - info->sprite[i].x) * (player->x - info->sprite[i].x) + (player->y - info->sprite[i].y) * (player->y - info->sprite[i].y)));
	info_sort(info);
}

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
	idx = 0;
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
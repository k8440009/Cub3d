#include "../includes/cub3d.h"

/*
void		init_player(&info->player)
{

}
*/

int			init_map(t_info *info, t_list *lst)
{
	int		y;
	int		x;

	info->map_height = ft_lstsize(lst);
	if (!(info->map = (char **)malloc(sizeof(char *) * (info->map_height))))
		return (print_error("init_map error 1", info));
	y = 0;
	info->map_width = get_max_line_size(lst);
	while (lst)
	{
		if (!(info->map[y] = (char *)malloc(sizeof(char) * (info->map_width + 1))))
			return(print_error("init map error 2", info));
		x = 0;
		while (x++ < (int)ft_strlen(lst->content))
			info->map[y][x] = 0;
		while (x++ < info->map_width)
			info->map[y][x] = ' ';
		info->map[y][info->map_width] = '\0';
		y++;
		lst = lst->next;
	}
	return (1);
}

int			init_direction(t_info *info, int y, int x, int *dir_count)
{
	if (info->map[y][x] == 'N')
		info->dir = NORTH;
	else if (info->map[y][x] == 'E')
		info->dir = EAST;
	else if (info->map[y][x] == 'S')
		info->dir = SOUTH;
	else if (info->map[y][x] == 'W')
		info->dir = WEST;
	else
		return (0);
	info->player.y = 0.5f + y;
	info->player.x = 0.5f + x;
	(*dir_count)++;
	return (1);
}

void		init_player_direction(t_info *info)
{
	int		rotate;

	rotate = 0;
	if (info->dir == NORTH)
		rotate = 270;
	else if (info->dir == EAST)
		rotate = 0;
	else if (info->dir == SOUTH)
		rotate = 90;
	else if (info->dir == WEST)
		rotate = 180;
	rotate_player(&info->player, rotate * (PI / 180));
}

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
	info->sprite = NULL;
	info->win_width = 0;
	info->win_height = 0;
	info->map_width = 0;
	info->map_height = 0;
	info->map = NULL;
	info->north_texture_path = NULL;
	info->south_texture_path = NULL;
	info->west_texture_path = NULL;
	info->east_texture_path = NULL;
	info->floor_color = 0;
	info->ceiling_color = 0;
	info->count_sprite = 0;
}
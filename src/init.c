#include "../includes/cub3d.h"

int			init_map(t_info *info, t_list *lst)
{
	int		r;
	int		c;

	info->map_height = ft_lstsize(lst);
    printf("map_height : %d\n", info->map_height);
	if (!(info->map = (char **)malloc(sizeof(char *) * (info->map_height))))
		return (print_error("init_map error 1", info));
	r = 0;
	info->map_width = get_max_line_size(lst);
    printf("map_width : %d\n", info->map_width);
	while (lst)
	{
		if (!(info->map[r] = (char *)malloc(sizeof(char) * (info->map_width + 1))))
			return(print_error("init map error 2", info));
		c = 0;
		while (c++ < (int)ft_strlen(lst->content))
			info->map[r][c] = 0;
		while (c++ < info->map_width)
			info->map[r][c] = ' ';
		info->map[r][info->map_width] = '\0';
		r++;
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
	info->player.start_r = y;
	info->player.start_c = x;
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
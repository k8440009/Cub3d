#include "../includes/cub3d.h"

void		set_direction(t_info *info, int y, int x, int *dir_count)
{
	if (info->map[y][x] == 'N')
		info->dir = NORTH;
	else if (info->map[y][x] == 'E')
		info->dir = EAST;
	else if (info->map[y][x] == 'S')
		info->dir = SOUTH;
	else if (info->map[y][x] == 'W')
		info->dir = WEST;
	info->state.r = y;
	info->state.c = x;
	info->player.y = 0.5f + y;
	info->player.x = 0.5f + x;
	(*dir_count)++;
}

void		save_map_data(t_info *info, int y, int x, int *dir_count)
{
	if (info->map[y][x] == '2')
		info->count_sprite++;
	else if (info->map[y][x] == 'N' || info->map[y][x] == 'E'
			|| info->map[y][x] == 'S' || info->map[y][x] == 'W')
		set_direction(info, y,x, dir_count);
}

int			set_map_data(t_info *info, t_list *lst)
{
	int		y;
	int		x;
	char	*line;
	int		dir_count;

	y = -1;
	dir_count = 0;
	while (++y < info->map_height)
	{
		x = -1;
		line = (char *)lst->content;
		while (++x < (int)ft_strlen(line))
		{
			if (!is_map_arg(line[x]))
				return (print_error("map argument error\n", info));
			info->map[y][x] = line[x];
			save_map_data(info, y, x, &dir_count);
		}
		lst = lst->next;
	}
	if (dir_count == 0 || dir_count > 1)
		return (print_error("fill_map error2\n", info));
	return (1);
}

int			parse_map(t_info *info, t_list *lst)
{
	if (!init_map(info, lst))
		return (print_error("init_map error", info));
	if (!set_map_data(info, lst))
		return (print_error("set_map_data error\n", info));
	ft_lstclear(&lst, free);
	if (!check_map(info) || !check_valid_map(info))
		return (print_error("check_valid_map error", info));
	return (1);
}
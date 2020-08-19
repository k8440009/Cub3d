#include "../includes/cub3d.h"

void		dfs()
{
	// 방문함
	// 에러 체크
}

int			check_map_left(t_info *info, int y, int x)
{
	while (info->map[y][x] == ' ')
		y++;
	if (info->map[y][x] != '1')
		return  (print_error("check_map_left1", info));
	return (1);
}
int			check_map_right(t_info *info, int y, int x)
{
	if (info->map[y][x - 1] != '1')
		return  (print_error("check_map_right1", info));
	return (1);
}

int			check_map_bottom(t_info *info, int y)
{
	int		x;

	x = -1;
	while (++x < (int)ft_strlen(info->map[0]))
	{
		if (!(info->map[y][x] == ' ' || info->map[y][x] == '1'))
			return (print_error("check_map_bottom1", info));
	}
	return (1);
}

int			check_map_middle(t_info *info, int y, int x)
{
	if (y > 0 && y < info->map_height - 1)
	{
		if (info->map[y - 1][x] == ' ' || info->map[y + 1][x] == ' ')
			if (info->map[y][x] != ' ' && info->map[y][x] != '1')
				return  (print_error("check_map_middle1", info));
	}
	if (x > 0 && x < info->map_width - 1)
	{
		if (info->map[y][x - 1] == ' ' || info->map[y][x + 1] == ' ')
			if (info->map[y][x] != ' ' && info->map[y][x] != '1')
				return  (print_error("check_map_middle1", info));
	}
	return (1);
}

int			check_map_top(t_info *info)
{
	int		x;

	x = -1;
	while (++x < (int)ft_strlen(info->map[0]))
	{
		if (!(info->map[0][x] == ' ' || info->map[0][x] == '1'))
			return (print_error("check_map_top1", info));
	}
	return (1);
}
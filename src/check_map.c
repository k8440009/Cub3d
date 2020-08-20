#include "../includes/cub3d.h"

void		dfs(t_info *info)
{

}

int			init_visited(t_info *info)
{
	int		y;
	int		x;

	if (!(info->visited = (char **)malloc(sizeof(char *) * (info->map_height))))
		return (print_error("init_visited error 1", info));
	y = 0;
	while (y < info->map_height)
	{
		if (!(info->visited[y] = (char *)malloc(sizeof(char) * (info->map_width + 1))))
			return (print_error("init_visited error 2", info));
		x = 0;
		while (x++ < info->map_width)
			info->visited[y][x] = 'f';
		info->visited[y][info->map_width] = '\0';
	}
	return (1);
}

int			check_valid_map(t_info *info)
{
	if (!init_visited(info))
		return (print_error("check_valid_map error 1", info));
	// dfs
	// check
}
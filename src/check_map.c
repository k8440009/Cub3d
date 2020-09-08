#include "../includes/cub3d.h"

int			valid_map(t_info *info)
{
	int		r;
	int		c;

	r = -1;
	while (++r < info->map_height)
	{
		c = -1;
		while (++c < info->map_width)
		{
			if (info->map[r][c] == ' ' && info->visited[r][c] == 1)
				return (0);
		}
	}
	return (1);
}

void		dfs(t_info *info, int r, int c)
{
	int		dir;
	int		nr;
	int		nc;

	if (!(info->state.flag))
		return ;
	dir = 0;
	info->visited[r][c] = 1;
	while (dir < 4)
	{
		nr = r + info->state.dr[dir];
		nc = c + info->state.dc[dir];
		if ((0 <= nr && nr < info->map_height) && (0 <= nc && nc <= info->map_width)
			&& info->visited[nr][nc] == 0 && info->map[nr][nc] != '1')
			dfs(info, nr, nc);
		else if (nr < 0 || nr >= info->map_height || nc < 0 || nc >= info->map_width)
		{
			info->state.flag = 0;
			return ;
		}
		dir++;
	}
}

int			init_visited(t_info *info)
{
	int		r;
    
	if (!(info->visited = (char**)ft_calloc(info->map_height, sizeof(char *))))
		return (print_error("init_visited error 1", info));
	r = -1;
	while (++r < info->map_height)
	{
		if (!(info->visited[r] = (char *)ft_calloc(info->map_width + 1, sizeof(char))))
			return (print_error("init_visited error 2", info));
		info->visited[r][info->map_width] = '\0';
	}
	return (1);
}

int			check_valid_map(t_info *info)
{
	if (!init_visited(info))
		return (print_error("init_visited error", info));
	init_state(info);
	dfs(info, info->state.r, info->state.c);
	if (!(info->state.flag) || !valid_map(info))
		return (print_error("valid_map error", info)); 
	return (1);
}
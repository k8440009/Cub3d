#include "../includes/cub3d.h"

int			valid_map(t_info *info)
{
	int		r;
	int		c;

	r = 0;
	while (r < info->map_height)
	{
		while (c < info->map_width)
		{
			if (info->map[r][c] == '0' && info->visited[r][c] == FALSE)
				return (0);
			c++;
		}
		r++;
	}
	return (1);
}

void		dfs(t_info *info, t_state *state, int r, int c)
{
	int		dir;
	int		nr;
	int		nc;

	if (!(state->flag))
		return ;
	dir = 0;
	info->visited[r][c] = TRUE;
	while (dir < 4)
	{
		nr = r + state->dr[dir];
		nc = c + state->dc[dir];
		if (nr < 0 || nr >= info->map_height || nc < 0 || nc >= info->map_width 
			|| info->visited[nr][nc] == TRUE)
			return ;
		dfs(info, state, nr, nc);
		dir++;
	}
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
			info->visited[y][x] = FALSE;
		info->visited[y][info->map_width] = '\0';
	}
	return (1);
}

void		init_state(t_info *info, t_state *state)
{
	state->dr[0] = -1;
	state->dr[1] = 0;
	state->dr[2] = 1;
	state->dr[3] = 0;
	state->dr[0] = 0;
	state->dr[1] = 1;
	state->dr[2] = 0;
	state->dr[3] = -1;
	state->r = info->player.start_r;
	state->c = info->player.start_c;
	state->flag = 1;
	info->visited[state->r][state->c] = TRUE;
}

int			check_valid_map(t_info *info)
{
	t_state		state;

	if (!init_visited(info))
		return (print_error("check_valid_map error 1", info));
	init_state(info, &state);
	dfs(info, &state, info->player.start_r, info->player.start_c);
	if (!(state.flag))
		return (print_error("check_valid_map error 2", info)); 
	if (!(valid_map(info)))
		return (print_error("check_valid_map error 3", info)); 
	free_two_pointer(info->visited);
	return (1);
}
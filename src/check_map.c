#include "../includes/cub3d.h"

int			valid_map(t_info *info)
{
	int		r;
	int		c;

	r = -1;
	while (++r < info->map_height)
	{
		while (++c < info->map_width)
		{
			if (info->map[r][c] == ' ' && info->visited[r][c] == TRUE)
				return (0);
		}
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
    //printf("%d %d\n", r, c);
	while (dir < 4)
	{
		nr = r + state->dr[dir];
		nc = c + state->dc[dir];
		if ((0 <= nr && nr < info->map_height) && (0 <= nc && nc <= info->map_width)
			&& info->visited[nr][nc] == FALSE && info->map[nr][nc] != '1')
			dfs(info, state, nr, nc);
		else if (nr < 0 || nr >= info->map_height || nc < 0 || nc >= info->map_width)
		{
			state->flag = 0;
			return ;
		}
		dir++;
	}
}

int			init_visited(t_info *info)
{
	int		r;
	int		c;
    
	if (!(info->visited = (char **)malloc(sizeof(char *) * (info->map_height))))
		return (print_error("init_visited error 1", info));
	r = -1;
	while (++r < info->map_height)
	{
		if (!(info->visited[r] = (char *)malloc(sizeof(char) * (info->map_width + 1))))
			return (print_error("init_visited error 2", info));
		c = -1;
		while (++c < info->map_width)
			info->visited[r][c] = '0';
		info->visited[r][info->map_width] = '\0';
	}
	return (1);
}

void		init_state(t_info *info, t_state *state)
{
	state->dr[0] = -1;
	state->dr[1] = 0;
	state->dr[2] = 1;
	state->dr[3] = 0;
	state->dc[0] = 0;
	state->dc[1] = 1;
	state->dc[2] = 0;
	state->dc[3] = -1;
	state->r = info->player.start_r;
	state->c = info->player.start_c;
	state->flag = 1;
}

int			check_valid_map(t_info *info)
{
	t_state		state;

    int r, c;
	if (!init_visited(info))
		return (print_error("check_valid_map error 1", info));
	init_state(info, &state);
	dfs(info, &state, info->player.start_r, info->player.start_c);
	if (!(state.flag))
		return (print_error("check_valid_map error 2", info)); 
	if (!(valid_map(info)))
		return (print_error("check_valid_map error 3", info));
	//free_two_pointer(info->visited);
	return (1);
}
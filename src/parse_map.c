#include "../includes/cub3d.h"

int		check_valid_map(t_info *info)
{
	int		y;
	int		x;

	if (!check_map_top(info))
		return (print_error("check_valid_map1", info));
	y = 0;
	while (y < info->map_height - 1)
	{
		x = 0;
		if (!check_map_left(info, y, x))
			return ("check_valid_map2", info);
		while (x < (int)ft_strlen(info->map[y]))
		{
			if (!check_map_middle(info, y, x))
				return ("check_valid_map3", info);
			x++;
		}
		if (!check_map_right(info, y, x))
			return ("check_valid_map4", info);
		y++;
	}
	if (!check_map_bottom(info, y))
		return ("check_valid_map5", info);
	return (1);
}

int		init_direction(t_info *info, int y, int x, int *dir_count)
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

int		fill_map(t_info *info, t_list *lst)
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
			if (is_map_arg(line[x]) == -1)
				return (print_error("fill_map error 1", info));
			info->map[y][x] = line[x];
			if (info->map[y][x] == '2')
				info->count_sprite++;
			else
				init_direction(info, y,x, &dir_count);
		}
		lst = lst->next;
	}
	if (dir_count == 0 || dir_count > 1)
		return (print_error("fill_map error 2", info));
	return (1);
}

int				get_max_line_size(t_list *lst)
{
	int		max_size;
	int		size;

	max_size = 0;
	while (lst)
	{
		size = ft_strlen((char *)lst->content);
		if (size > max_size)
			max_size = size;
		lst = lst->next;
	}
	return (max_size);
}

int		init_map(t_info *info, t_list *lst)
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

int		parse_map(t_info *info, t_list *lst)
{
	if (!init_map(info, lst))
		return (print_error("init_map error", info));
	if (!fill_map(info, lst))
		return (print_error("fill_map error", info));
	ft_lstclear(&lst, free);
	if (!check_valid_map(info))
		return (print_error("check_valid_map", info));
	return (1);
}

int		read_map(t_info *info, char *line)
{
	t_list		*lst;

	info->map_width = 0;
	info->map_height = 0;
	lst = ft_lstnew(ft_strdup(line));
	free(line);
	while (get_next_line(info->fd, &line) > 0)
	{
		ft_lstadd_back(&lst, ft_lstnew(ft_strdup(line)));
		free(line);
	}
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup(line)));
	free(line);
	if (!parse_map(info, lst))
		return (print_error("parse_map", info));
	return (1);
}

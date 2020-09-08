#include "../includes/cub3d.h"

int			pre_process_map(t_info *info, char *line)
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
        return (print_error("read_map error1\n", info));
	return (1);
}

int			parse_element_line(t_info *info, char *line)
{
	if (ft_strncmp(line, "R ", 2) == 0)
		return (get_screen_size(info, line + 2));
	else if (ft_strncmp(line, "NO ", 3) == 0)
		return (get_texture(info, line + 3, NORTH));
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (get_texture(info, line + 3, SOUTH));
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (get_texture(info, line + 3, WEST));
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (get_texture(info, line + 3, EAST));
	else if (ft_strncmp(line, "S ", 2) == 0)
		return (get_texture(info, line + 2, SPRITE));
	else if (ft_strncmp(line, "F ", 2) == 0)
		return (get_color(info, line + 2, FLOOR));
	else if (ft_strncmp(line, "C ", 2) == 0)
		return (get_color(info, line + 2, CEILING));
	else if (line[0] == '\0')
		return (1);
	return (0);
}

int			pre_process_cub(t_info *info, char *path)
{
	char		*line;
	int			gnl_ret;
	int			ret;

	if ((info->fd = open(path, O_RDONLY)) == -1)
		return (print_error("read cub file error", info)); 
	while ((gnl_ret = get_next_line(info->fd, &line)) > 0)
	{
		if ((ret = parse_element_line(info, line)) == 0)
			break;
		free(line);
	}
	if (gnl_ret == -1)
		return (print_error("read file error", info));
	if (!check_element(info))
		return (print_error("check element error", info));
	if (!pre_process_map(info, line))
		return (print_error("pree_process_map error", info));
	if (!set_sprite(info))
		return (print_error("set sprite error", info));
	return (1);
}
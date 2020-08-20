#include "../includes/cub3d.h"

int			read_map(t_info *info, char *line)
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

int			read_element(t_info *info, char *line)
{
	int		ret;

	while ((ret = get_next_line(info->fd, &line)) > 0)
	{
		if (!parse_element(info, line))
			break;
		free(line);
	}
	if (ret == -1)
		return (print_error("parse_cub error2", info));
	return (1);
}

int			parse_cub(t_info *info, char *path)
{
	char	*line;
	int		ret;

	info->fd = open(path, O_RDONLY);
	if (!read_element(info, line))
		return (print_error("parse_cub error1", info));
	if (!read_map(info, line))
		return (print_error("parse_cub error2", info));
	/*
	if (!check_info(info))
		return (print_error("parse_cub error3", info));
	if (!set_sprite(info))
		return (print_error("parse_cub error4", info));
	*/
	return (1);
}


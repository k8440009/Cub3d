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
    if (!parse_map(info, lst))
        return (print_error("read_map error1\n", info));
	return (1);
}

int			pre_process_cub(t_info *info, char *path)
{
	char		*line;
	int			ret1;
	int			ret2;

	init_info(info);
	info->fd = open(path, O_RDONLY);
	while ((ret1 = get_next_line(info->fd, &line)) > 0)
	{
		if ((ret2 = parse_element_line(info, line)) == 0)
			break;
		if (ret2 == -1)
			return (print_error("read element error1", info));
		free(line);
	}
	if (!pre_process_map(info, line))
		return (print_error("pree_process_cub1 error", info));
	return (1);
}
#include "../includes/cub3d.h"

int		read_map(t_info *info, char *line)
{
	t_list	*lst;
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
		return (exit_error(info));
	return (1);
}
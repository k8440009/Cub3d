#include "../includes/cub3d.h"

int			get_max_line_size(t_list *lst)
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

int			ft_exit(int ret)
{
	exit(ret);
	return (ret);
}
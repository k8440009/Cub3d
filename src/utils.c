#include "cub3d.h"

int		exit_error(t_info *info)
{
	ft_putstr("Error\n");
	if (info->fd)
		close(info->fd);
	exit(0);
	return (-1);
}
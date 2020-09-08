#include "../includes/cub3d.h"

int			print_error(char *message, t_info *info)
{
	ft_putstr(message);
	if (info->fd > 0)
		close(info->fd);
	exit(0);
	return (0);
}
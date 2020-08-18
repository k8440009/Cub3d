#include "../includes/cub3d.h"

int			element_error(t_info *info)
{
	ft_putstr("Element Error\n");
	if (info->fd > 0)
		close(info->fd);
	exit(0);
	return (0);
}
int			map_error(t_info *info)
{
	ft_putstr("Map Error\n");
	if (info->fd > 0)
		close(info->fd);
	exit(0);
	return (0);
}

int			print_error(int	error_code, t_info *info)
{
	if(error_code == ELEMENT_ERROR)
		return (element_error(info));
	else if (error_code == MAP_ERROR)
		return (map_error(info));
}
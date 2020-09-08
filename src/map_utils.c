#include "../includes/cub3d.h"

int			is_map_arg(int c)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W'
	|| c == ' ' || (c >= '0' && c <= '2') || c == '\n'
	|| c == '\0')
		return (1);
	return (0); 
}
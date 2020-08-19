#include "../includes/cub3d.h"

int				is_map_arg(int c)
{
	if (is_dir(c) == 1 || c == ' ' || (c >= '0' && c <= '2')
		|| c == '\n' || c == '\0')
		return (1);
	return (-1);
}

void			free_two_pointer(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
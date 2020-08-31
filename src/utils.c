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

int			is_map_arg(int c)
{
    printf("%d", c);
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W'
	|| c == ' ' || (c >= '0' && c <= '2') || c == '\n'
	|| c == '\0')
		return (1);
    // printf("%c, %d", (char)c, c);
	return (0); 
}

void		free_two_pointer(char **str)
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
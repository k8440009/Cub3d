#include "../includes/cub3d.h"

int			free_cub(t_info *info)
{
	if (info->img.img)
		mlx_destroy_image(info->mlx, info->img.img);
	if (info->sprite)
		ft_free(info->sprite);
	if (info->buf)
		free_two_pointer((void *)info->buf);
	if (info->z_buf)
		ft_free(info->z_buf);
	if (info->texture)
		ft_free(info->texture);
	if (info->map)
		free_two_pointer(info->map);
	if (info->mlx && info->win)
		mlx_destroy_window(info->mlx, info->win);
	ft_exit(0);
	return (0);
}

int			ft_exit(int ret)
{
	exit(ret);
	return (ret);
}

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
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W'
	|| c == ' ' || (c >= '0' && c <= '2') || c == '\n'
	|| c == '\0')
		return (1);
	return (0); 
}

void		ft_free(void *s)
{
	free(s);
	s = 0;
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
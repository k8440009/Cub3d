/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 03:46:46 by sungslee          #+#    #+#             */
/*   Updated: 2020/09/09 03:46:52 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			free_cub(t_info *info)
{
	if (info->img.img)
		mlx_destroy_image(info->mlx, info->img.img);
	if (info->sprite)
		ft_free(info->sprite);
	if (info->buf)
		free_two_arr((void *)info->buf);
	if (info->z_buf)
		ft_free(info->z_buf);
	if (info->texture)
		ft_free(info->texture);
	if (info->map)
		free_two_arr(info->map);
	if (info->visited)
		free_two_arr(info->visited);
	if (info->mlx && info->win)
		mlx_destroy_window(info->mlx, info->win);
	ft_exit(0);
	return (0);
}

void		free_two_arr(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void		ft_free(void *s)
{
	free(s);
	s = 0;
}

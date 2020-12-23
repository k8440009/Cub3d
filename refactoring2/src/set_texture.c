/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 04:19:33 by sungslee          #+#    #+#             */
/*   Updated: 2020/09/09 04:19:34 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		cast_floor_ceiling(t_info *info)
{
	int	y;
	int	x;

	y = -1;
	while (++y < info->win_height)
	{
		x = -1;
		while (++x < info->win_width)
		{
			if (y > info->win_height / 2)
				info->buf[y][x] = info->floor_color;
			else
				info->buf[y][x] = info->ceiling_color;
		}
	}
}

int			load_image(t_info *info, int *texture, char *path, t_img *img)
{
	int		r;
	int		c;

	if (!(img->img = mlx_xpm_file_to_image(info->mlx, path,
		&img->width, &img->height)))
		return (print_error("load_iamge error", info));
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp,
		&img->size_l, &img->endian);
	r = -1;
	while (r++ < img->height)
	{
		c = -1;
		while (++c < img->width)
			texture[img->width * r + c] = img->data[img->width * r + c];
	}
	mlx_destroy_image(info->mlx, img->img);
	return (1);
}

int			set_texture(t_info *info)
{
	t_img	img;

	if (!load_image(info, info->texture[0], info->west_texture_path, &img))
		return (print_error("set west texture error", info));
	if (!load_image(info, info->texture[1], info->east_texture_path, &img))
		return (print_error("set east texture error", info));
	if (!load_image(info, info->texture[2], info->north_texture_path, &img))
		return (print_error("set north texture error", info));
	if (!load_image(info, info->texture[3], info->south_texture_path, &img))
		return (print_error("set south texture error", info));
	if (!load_image(info, info->texture[4], info->sprite_texture_path, &img))
		return (print_error("set sprite texture error", info));
	ft_free(info->north_texture_path);
	ft_free(info->east_texture_path);
	ft_free(info->south_texture_path);
	ft_free(info->west_texture_path);
	ft_free(info->sprite_texture_path);
	return (1);
}

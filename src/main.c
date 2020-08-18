/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 19:07:12 by sungslee          #+#    #+#             */
/*   Updated: 2020/08/14 21:01:05 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdio.h>

char		*error;

int			set_info(t_info *info, char *path)
{
	init_player(&info->player);
	if (!parse_cub(info, path))
		return error;
	init_player_direction(info);
	info->mlx = mlx_init();
	if (!init_buffer(info))
		return (error);
	load_texture(info);
	info->img.img = mlx_new_image();
	info->img.data = mlx_get_data_addr();
	return (1);
}

int			process_option(t_info *info, int option)
{
	if (option == 1)
	{
		raycasting(info);
		sprite_raycasting(info, &info->player);
		if (!save_bmp(info))
			return (error);
		exit(0);
	}
	else
	{
		mlx_new_window();
		mlx_hook();
		mlx_loop_hook();
		mlx_loop();
	}
	
}

int			main(int argc, char **argv)
{
	t_info		info;
	int			option;

	// option = (argc >= 2 && (ft_strncmp(argv[1], "--save", 6) == 0)) ? 1 : 0;
	if (argc < option + 2)
		return (error);
	if (!set_info(&info, argv[option + 1]))
		return (error);
	if (!process_option(&info, option))
		return (error);
	free_cub(&info);
	return (0);
}
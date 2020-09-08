/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 03:57:52 by sungslee          #+#    #+#             */
/*   Updated: 2020/09/09 03:57:54 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_player(t_info *info, t_player *player, double move_speed)
{
	if (info->map[(int)player->y]
	[(int)(player->x + player->dir_x * move_speed)] != '1')
		player->x += player->dir_x * move_speed;
	if (info->map[(int)(player->y + player->dir_y * move_speed)]
	[(int)player->x] != '1')
		player->y += player->dir_y * move_speed;
}

void	move_player_left_right(t_info *info, t_player *player,
		double move_speed)
{
	if (info->map[(int)player->y]
	[(int)(player->x + player->dir_y * move_speed)] != '1')
		player->x += player->dir_y * move_speed;
	if (info->map[(int)(player->y + -player->dir_x * move_speed)]
	[(int)player->x] != '1')
		player->y += -player->dir_x * move_speed;
}

void	rotate_player(t_player *player, double rotate_speed)
{
	double	old_vec_dir_x;
	double	old_plane_x;

	old_vec_dir_x = player->dir_x;
	player->dir_x = player->dir_x *
	cos(rotate_speed) - player->dir_y * sin(rotate_speed);
	player->dir_y = old_vec_dir_x *
	sin(rotate_speed) + player->dir_y * cos(rotate_speed);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x *
	cos(rotate_speed) - player->plane_y * sin(rotate_speed);
	player->plane_y = old_plane_x *
	sin(rotate_speed) + player->plane_y * cos(rotate_speed);
}

int		key_press(int key, t_info *info)
{
	if (key == K_W || key == K_AR_U)
		move_player(info, &info->player, info->player.move_speed);
	if (key == K_S || key == K_AR_D)
		move_player(info, &info->player, -info->player.move_speed);
	if (key == K_A)
		move_player_left_right(info, &info->player, -info->player.move_speed);
	if (key == K_D)
		move_player_left_right(info, &info->player, info->player.move_speed);
	if (key == K_AR_L)
		rotate_player(&info->player, info->player.rot_speed);
	if (key == K_AR_R)
		rotate_player(&info->player, -info->player.rot_speed);
	if (key == K_ESC)
		ft_exit(0);
	return (0);
}

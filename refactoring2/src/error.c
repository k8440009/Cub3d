/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 03:46:28 by sungslee          #+#    #+#             */
/*   Updated: 2020/09/09 03:46:30 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			print_error(char *message, t_info *info)
{
	ft_putstr(message);
	if (info->fd > 0)
		close(info->fd);
	exit(0);
	return (0);
}

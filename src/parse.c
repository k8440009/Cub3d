/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 19:22:43 by sungslee          #+#    #+#             */
/*   Updated: 2020/08/14 20:33:41 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdio.h>

int			parse_line(t_info *info, char *line)
{
	if (line[0] == '\0')
		return(1);
	return (0);
}

int			parse_cub(t_info *info, char *path)
{
	char	*line;
	int		ret;

	init_info(info);

	info->fd = open(path, O_RDONLY);
	while (get_next_line(info->fd, &line) > 0)
	{
		if ((ret = parse_line(info, line)) == -1)
			return (exit_error(info));
		if (ret == 0)
			break;
		free(line);
	}
	if (!read_map(info, line))
	return (1);
}
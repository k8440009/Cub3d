/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 03:56:09 by sungslee          #+#    #+#             */
/*   Updated: 2020/09/09 03:56:11 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			init_visited(t_info *info)
{
	int		r;

	if (!(info->visited = (char**)ft_calloc(info->map_height, sizeof(char *))))
		return (print_error("init_visited error 1", info));
	r = -1;
	while (++r < info->map_height)
	{
		if (!(info->visited[r] = (char *)
			ft_calloc(info->map_width + 1, sizeof(char))))
			return (print_error("init_visited error 2", info));
		info->visited[r][info->map_width] = '\0';
	}
	return (1);
}

void		init_state(t_info *info)
{
	info->state.dr[0] = -1;
	info->state.dr[1] = 0;
	info->state.dr[2] = 1;
	info->state.dr[3] = 0;
	info->state.dc[0] = 0;
	info->state.dc[1] = 1;
	info->state.dc[2] = 0;
	info->state.dc[3] = -1;
	info->state.flag = 1;
}

int			init_map(t_info *info, t_list *lst)
{
	int		r;
	int		c;

	info->map_height = ft_lstsize(lst);
	if (!(info->map = (char **)malloc(sizeof(char *) * (info->map_height))))
		return (print_error("init_map error 1", info));
	r = 0;
	info->map_width = get_max_line_size(lst);
	while (lst)
	{
		if (!(info->map[r] = (char *)
		malloc(sizeof(char) * (info->map_width + 1))))
			return (print_error("init map error 2", info));
		c = 0;
		while (c++ < (int)ft_strlen(lst->content))
			info->map[r][c] = 0;
		while (c++ < info->map_width)
			info->map[r][c] = ' ';
		info->map[r][info->map_width] = '\0';
		r++;
		lst = lst->next;
	}
	return (1);
}

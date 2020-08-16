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

int			set_info(t_info *info, char *path)
{
	parse_cub(info, path);
	return (1);
}

int			main(int argc, char **argv)
{
	t_info	info;
	int		option;

	option = (argc >= 2 && (ft_strncmp(argv[1], "--save", 6) == 0)) ? 1 : 0;
	if (argc < option + 2)
		printf("add map\n");
	
	int fd;
	int ret;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("get_next_line : %s\n", line);
		printf("return value : %d\n\n", ret);
		free(line);
	}
	printf("get_next_line : %s\n", line);
	printf("return value : %d\n", ret);
	free(line);
	
}
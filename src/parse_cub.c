#include "../includes/cub3d.h"

int				check_element(char *line, int type)
{
	int		idx;

	idx = 0;
	while (line[idx])
	{
		if (type == NUMBER)
		{
			if (!ft_isdigit(line[idx]))
				return (0);
		}
		idx++;
	}
	return (1);
}

int				get_screen_size(t_info *info, char *line)
{
	char	**data;

	if (!(data = ft_split(line, ' ')))
	{
		printf("split error1\n");
		return (print_error(ELEMENT_ERROR, info));
	}
	if (!data || !data[0] || !data[1])
	{
		printf("split error2\n");
		return (print_error(ELEMENT_ERROR, info));
	}
	if (!check_element(data[0], NUMBER) || !check_element(data[1], NUMBER))
	{
		printf("split error 3\n");
		return (print_error(ELEMENT_ERROR, info));
	}
	info->width = ft_atoi(data[0]);
	info->height = ft_atoi(data[1]);
	printf("width : %d\n", info->width);
	printf("height : %d\n", info->height);
	if (info->width <= 0 || info->height <= 0)
	{
		printf("width, height error\n");
		return (print_error(ELEMENT_ERROR, info));
	}
	return (1);
}

int				get_texture(t_info *info, char *line, int direction)
{

}

int				get_color(t_info *info, char *line, int direction)
{

}

int			parse_element(t_info *info, char *line)
{
	if (ft_strncmp(line, "R ", 2) == 0)
		return (get_screen_size(info, line + 2));
	else if (ft_strncmp(line, "NO ", 3) == 0)
		return (get_texture(info, line + 3, NORTH));
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (get_texture(info, line + 3, SOUTH));
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (get_texture(info, line + 3, WEST));
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (get_texture(info, line + 3, EAST));
	else if (ft_strncmp(line, "S ", 2) == 0)
		return (get_texture(info, line + 2, SOUTH));
	else if (ft_strncmp(line, "F ", 2) == 0)
		return (get_color(info, line + 2, FLOOR));
	else if (ft_strncmp(line, "C ", 2) == 0)
		return (get_color(info, line + 2, CEILING));
	else if (line[0] == '\0')
		return (1);
	return (0);
}

int			parse_cub(t_info *info, char *path)
{
	char	*line;
	int		ret;

	info->fd = open(path, O_RDONLY);
	while ((ret = get_next_line(info->fd, &line)) > 0)
	{
		if (ret == 1)	// 라인 하나 읽음
			parse_element(info, line);
		else if (ret == 0)	// EOF
			break;
		else	// 에러
		{
			printf("parse_cub error\n");
			print_error(ELEMENT_ERROR, info);
		}
	}
	return (1);
	//if (!read_map(info, line))
	//	return (print_error(MAP_ERROR, info));
}

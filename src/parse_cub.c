#include "../includes/cub3d.h"

int				str_length(char **str)
{
	int 	i;

	i = 0;
	while (str++)
		i++;
	return (i);
}

int				get_screen_size(t_info *info, char *line)
{
	char	**data;
	// 인자가 3개 이상일 때 에러 처리 추가
	if (!(data = ft_split(line, ' ')))
		return (print_error("split 1 error", info));
	if (!data || !data[0] || !data[1])
		return (print_error("split 2 error", info));
	printf("data[0] size : %d\n", ft_strlen(data[0]));
	printf("data[1] size : %d\n", ft_strlen(data[1]));
	info->width = ft_atoi(data[0]);
	info->height = ft_atoi(data[1]);
	if (info->width <= 0 || info->height <= 0)
		return (print_error("split 3 error", info));
	return (1);
}

int				get_texture(t_info *info, char *line, int type)
{
	if (type == NORTH)
		info->north_texture_path = ft_strdup(line);
	else if (type == EAST)
		info->east_texture_path = ft_strdup(line);
	else if (type == SOUTH)
		info->south_texture_path = ft_strdup(line);
	else if (type == WEST)
		info->west_texture_path = ft_strdup(line);
	else if (type == SPRITE)
		info->sprite_texture_path = ft_strdup(line);
	else
		return (print_error("texture error", info));
	return (1);
}

int				get_color(t_info *info, char *line, int type)
{
	char	**rgb;
	int		color;
	int		i;

	/*
	** isprint를 사용하여 출력 가능한 곳만 남기고
	*/
	if (!(rgb = ft_split(line, ',')))
		return (print_error("get color error1\n", info));
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
		return (print_error("get color error 2\n", info));
	color = 0;
	i = 0;
	while (rgb[i])
	{
		color *= 256;
		color += ft_atoi(rgb[i]);
		i++;
	}
	free_two_pointer(rgb);
	if (type == FLOOR)
		info->floor_color = color;
	else if (type == CEILING)
		info->ceiling_color = color;
	return (1);
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
		return (get_texture(info, line + 2, SPRITE));
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
			print_error("parse_cub error", info);
		free(line);
	}
	return (1);
	//if (!read_map(info, line))
	//	return (print_error(MAP_ERROR, info));
}

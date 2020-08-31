#include "../includes/cub3d.h"

int			read_map(t_info *info, char *line)
{
	t_list		*lst;

    int size = ft_strlen(line);
	info->map_width = 0;
	info->map_height = 0;
	lst = ft_lstnew(ft_strdup(line));
    free(line);
	while (get_next_line(info->fd, &line) > 0)
	{
		ft_lstadd_back(&lst, ft_lstnew(ft_strdup(line)));
		free(line);
	}
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup(line)));
	if (!parse_map(info, lst))
        return (print_error("read_map error1\n", info));
	return (1);
}

int			read_element(t_info *info, char *line)
{
	int		ret;
    int     ret2;
	while ((ret = get_next_line(info->fd, &line)) > 0)
	{
		if ((ret2 = parse_element(info, line)) == 0)
			break;
        if (ret2 == -1)
            return (print_error("read element error1", info));
		free(line);
	}
    if (!read_map(info, line))
        return (print_error("parse_cub error2", info));
    //printf("ret1 : %d ret2 : %d\n", ret, ret2);
    //printf("%s\n", line);
	return (1);
}

int			parse_cub(t_info *info, char *path, char *line)
{
	int		ret;
    int     ret2;

	info->fd = open(path, O_RDONLY);
	if (!read_element(info, line))
		return (print_error("parse_cub error1", info));
    //printf("size : %d, %s\n", ft_strlen(line), line);
    /*
    if (!read_map(info, line))
        return (print_error("parse_cub error2", info));
    */
   /*
    printf("win_width : %d\n", info->win_width);
    printf("win_height : %d\n", info->win_height);
    printf("north texture : %s\n", info->north_texture_path);
    printf("south texture : %s\n", info->south_texture_path);
    printf("west texture : %s\n", info->west_texture_path);
    printf("east texture : %s\n", info->east_texture_path);
    printf("sprite texture : %s\n", info->sprite_texture_path);
    printf("floor_color : %d\n", info->floor_color);
    printf("ceiling_color : %d\n", info->ceiling_color);
    for (int r = 0; r < info->map_height; r++)
    {
        for(int c = 0; c < info->map_width; c++)
            printf("%c", info->map[r][c]);
        printf ("\n");
    }
    */
    /*
	if (!read_map(info, line))
		return (print_error("parse_cub error2", info));
	if (!check_info(info))
		return (print_error("parse_cub error3", info));
	if (!set_sprite(info))
		return (print_error("parse_cub error4", info));
	*/
	return (1);
}


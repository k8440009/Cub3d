#include "../includes/cub3d.h"

int			fill_map(t_info *info, t_list *lst)
{
	int		y;
	int		x;
	char	*line;
	int		dir_count;

	y = -1;
	dir_count = 0;
	while (++y < info->map_height)
	{
		x = -1;
		line = (char *)lst->content;
		while (++x < (int)ft_strlen(line))
		{
			if (!is_map_arg(line[x]))
				return (print_error("fill_map error1\n", info));
			info->map[y][x] = line[x];
			if (info->map[y][x] == '2')
				info->count_sprite++;
			else if (info->map[y][x] == 'N' || info->map[y][x] == 'E'
					|| info->map[y][x] == 'S' || info->map[y][x] == 'W')
				init_direction(info, y,x, &dir_count);
		}
		lst = lst->next;
	}
	if (dir_count == 0 || dir_count > 1)
		return (print_error("fill_map error2\n", info));
	return (1);
}

int			parse_map(t_info *info, t_list *lst)
{
	if (!init_map(info, lst))
		return (print_error("init_map error", info));
    for (int r = 0; r < info->win_width; r++)
    {
        for(int c = 0; c < info->win_height; c++)
        {
            printf("%c", info->map[r][c]);
        }
        printf ("\n");
    }
    /*
	if (!fill_map(info, lst))
		return (print_error("fill_map error0\n", info));
	ft_lstclear(&lst, free);
	if (!check_valid_map(info))
		return (print_error("check_valid_map", info));
    */
	return (1);
}

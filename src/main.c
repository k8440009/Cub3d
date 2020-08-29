#include "../includes/cub3d.h"

int		init_data(t_info *info, char *path)
{

	init_info(info);
	parse_cub(info, path);
	//init_player(&info->player);
	//init_player_direction(info);
	//init_buffer(info);
	//init_texture(info);
	//load_texture(info);
	//mlx_new_image(info->mlx, info->win_height, info->win_height);
	//mlx_get_data_addr()
    return (1);
}

int 	main(int argc, char **argv)
{
	t_info		info;

	init_data(&info, argv[1]);
	//if (!init_data(&info, argv[1]))
	//	return (error(&info));
	//if (parse_cub(&info, argv[1]))
	//free_cub(&info);
	return (0);
}

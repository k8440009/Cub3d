#include "../includes/cub3d.h"

int		process_option(t_info *info, int option)
{
	if (option == 1)
	{
		raycasting(info);
		//sprite_raycasting(info, &info->player);
		//if (!save_bmp(info))
		//	return (exit_error(info));
		exit(0);
	}
	else
	{
		info->win = mlx_new_window(info->mlx, info->win_width, info->win_height, "sungslee");
		mlx_hook(info->win, X_EVENT_KEY_PRESS, 0, key_press, info);
		mlx_hook(info->win, X_EVENT_KEY_EXIT, 0, ft_exit, 0);
		mlx_loop_hook(info->mlx, main_loop, info);
		mlx_loop(info->mlx);
	}
	return (1);
}

int		init_data(t_info *info, char *path)
{

	init_info(info);	// info 초기화
	if (!pre_process_cub(info, path))	// cub 전처리
		return (print_error("pre_process_cub error", info));
	init_player_direction(info);
	info->mlx = mlx_init();
	// 버퍼는 왜 넣는지 모르니 아직 작성 x
	if (!init_buffer(info))
		return (print_error("init_buffer error", info));
	if (!init_texture(info))
		return (print_error("init_texture error", info));
	set_texture(info);
	info->img.img = mlx_new_image(info->mlx, info->win_width, info->win_height);
	info->img.data = (int *)mlx_get_data_addr(info->img.img, &info->img.bpp, &info->img.size_l, &info->img.endian);
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
	printf("map_height : %d\n", info->map_height);
	printf("map_width : %d\n", info->map_width);
*/
	return (1);
}

int		main(int argc, char **argv)
{
    t_info		info;
	int			option;

	option = (argc >= 2 && (ft_strncmp(argv[1], "--save", 6) == 0)) ? 1 : 0;
	if (!init_data(&info, argv[1]))
		return (print_error("init_data error", &info));
	if (!process_option(&info, option))
		return (print_error("process_option error", &info));
	// free_cub(&info);
	return (0);
}
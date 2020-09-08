#include "../includes/cub3d.h"

int			process_option(t_info *info, int option)
{
	if (option == 1)
	{
		raycasting(info);
		sprite_raycasting(info, &info->player);
		if (!save_bmp(info))
			return (print_error("save bmp error", info));
		ft_exit(0);
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

int			init_game(t_info *info, char *path)
{
	init_info(info);
	init_player(&info->player);
	if (!pre_process_cub(info, path))
		return (print_error("pre_process_cub error", info));
	init_player_direction(info);
	info->mlx = mlx_init();
	if (!init_buffer(info))
		return (print_error("init_buffer error", info));
	if (!init_texture(info))
		return (print_error("init_texture error", info));
	if (!set_texture(info))
		return (print_error("set_texture error", info));
	info->img.img = mlx_new_image(info->mlx, info->win_width, info->win_height);
	info->img.data = (int *)mlx_get_data_addr(info->img.img, &info->img.bpp, &info->img.size_l, &info->img.endian);
	return (1);
}

int			main(int argc, char **argv)
{
	t_info		info;
	int 		option;

	option = (argc >= 3 && (ft_strncmp(argv[2], "--save", 6) == 0)) ? 1 : 0;
	if (!init_game(&info, argv[1]))
		return (print_error("init_game error", &info));
	if (!process_option(&info, option))
		return (print_error("process_option error", &info));
	free_cub(&info);
	return (0);
}
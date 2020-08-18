#include "../includes/cub3d.h"
#include <stdio.h>

int		init_data(t_info *info, int option)
{
	//init_info();
	//init_player();
}

int 	main(int argc, char **argv)
{
	t_info		info;

	//if (!init_data(&info, argv[1]))
	//	return (error(&info));
	parse_cub(&info, argv[1]);
	//if (parse_cub(&info, argv[1]))
	//free_cub(&info);
	return (0);
}

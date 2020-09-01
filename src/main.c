#include "../includes/cub3d.h"

int		init_data(t_info *info, char *path)
{

	init_info(info);
	pre_process_cub(info, path);

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
    for (int r = 0; r < info->map_height; r++)
    {
        for(int c = 0; c < info->map_width; c++)
            printf("%c", info->map[r][c]);
        printf ("\n");
    }
	return (1);
}

int		main(int argc, char **argv)
{
    t_info		info;

	init_data(&info, argv[1]);
	return (0);
}
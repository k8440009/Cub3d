#include "../includes/cub3d.h"

void setInfo(t_gameInfo *info){
	info->win_width = 0;
	info->win_height = 0;
	info->map_width = 0;
	info->map_height = 0;

	info->map_info = NULL;
}

void setMap(t_gameInfo *info){
}

void setPlayer(t_gameInfo *info){
	
}
int	init_game(t_gameInfo *info, char *path){

	t_mapInfo mapInfo;

	setInfo(info);
	setMap(info);
	setPlayer(info);

	get_player();

}

int main(int argc, char **argv){

	t_gameInfo info;

	if (argc == 2){
		set_gameInfo(&info, argv[1]);
		// parsing_mapfile(&info, argv[1]);
		process_option(&info, argv[1]);
	}
}
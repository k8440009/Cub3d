#ifndef CUB3D_H
#define CUB3D_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

#define NORTH 0x00
#define WEST 0x01
#define SOUTH 0x02
#define EAST 0x03
#define SPRITE 0x04
#define FLOOR 0x05
#define CEILING 0x06

typedef struct s_gameInfo{
	void *mlx;
	void *win;
	int fd;

	int win_width;
	int win_height;
	int map_width;
	int map_height;

	t_mapInfo *map_info;

} t_gameInfo;

typedef struct s_mapInfo{
	char **map;
	char *northTexturePath;
	char *southTexturePath;
	char *westTexturePath;
	char *eastTexturePath;
	char *spriteTexturePath;
	
	int floorColor;
	int ceilColor;
	
} t_mapInfo;

/*
* parsingCub.c
*/
int parsingCub(t_gameInfo *info, char *path);
/*
* getElement.c
*/
int getScreenSize(t_gameInfo *info, char *line);
int getColor(t_gameInfo *info, char *line, int type);
int getTexture(t_gameInfo *info, char *line, int type);
/*
	utils.c
*/
void freeTwoArr(char **arr);

t_list *ft_lstnew(void *content);
#endif
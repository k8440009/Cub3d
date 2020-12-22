#include "../includes/cub3d.h"

void		freeTwoArr(char **arr){
	int		i;

	i = 0;
	while (arr[i]){
		free(arr[i]);
		i++;
	}
	free(arr);
}
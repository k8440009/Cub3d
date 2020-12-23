#include "../includes/cub3d.h"

int	parsingMap(t_gameInfo *info, char *line){
	
}

int	parseElementLine(t_gameInfo *info, char *line){
	if (ft_strncmp(line, "R ", 2) == 0)
		return (getScreenSize(info, line + 2));
	else if (ft_strncmp(line, "NO ", 3) == 0)
		return (getTexture(info, line + 3, NORTH));
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (getTexture(info, line + 3, SOUTH));
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (getTexture(info, line + 3, WEST));
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (getTexture(info, line + 3, EAST));
	else if (ft_strncmp(line, "S ", 2) == 0)
		return (getTexture(info, line + 2, SPRITE));
	else if (ft_strncmp(line, "F ", 2) == 0)
		return (getColor(info, line + 2, FLOOR));
	else if (ft_strncmp(line, "C ", 2) == 0)
		return (getColor(info, line + 2, CEILING));
	else if (line[0] == '\0')
		return (1);
	return (0);
}

int parsingCub(t_gameInfo *info, char *path){
	char *line;
	int gnl_ret;
	int ret;
	int r = 0;
	int c = 0;

	if((info->fd = open(path, O_RDONLY)) == -1){
		return (-1);
	}
	while((gnl_ret = get_next_line(info->fd, &line)) > 0){
		
		if (!(parseElementLine(info, line)) == 0)
			break;
		free(line);
	}

	if (!parsingMap(info, line)){

	}
	
}
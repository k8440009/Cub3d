/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 19:07:55 by sungslee          #+#    #+#             */
/*   Updated: 2020/08/14 20:16:08 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/minilibx/mlx.h"
# include "../libs/libft/libft.h"
# include "get_next_line.h"
# include <math.h>
# include <fcntl.h>

typedef struct		s_info
{
	void		*mlx;
	void		*win;
}					t_info;

int			parse_cub(t_info *info, char *path);
#endif

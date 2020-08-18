#include <stdio.h>
#include <stdlib.h>
#include "../../../libs/minilibx/mlx.h"
#define X_EVENT_KEY_PRESS	2

typedef struct 	s_param
{
	int dir;
}				t_param;

# define KEY_ESC		53
# define KEY_Q			12
# define KEY_W			13
# define KEY_E			14
# define KEY_R			15
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

// - xpm파일을 불러와서 화면에 그려 창에 띄웁니다.

int main()
{
	void	*mlx;
	void	*win;
	void	*img;
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "mlx project");
	img = mlx_xpm_file_to_image(mlx, "../textures/wall_n.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 100, 100);
	mlx_loop(mlx);
	return (0);
}
#include <stdio.h>
#include <stdlib.h>
#include "../../../libs/minilibx/mlx.h"


/*
 W: x 변수에 1을 더함
  A: x 변수에서 1을 뺌
  ESC: 프로그램 종료 
  다른키: 현재 x값 출력
*/
#define X_EVENT_KEY_PRESS	2

typedef struct 	s_param
{
	int		x;
	int		y;
	char	str[3];
}				t_param;

# define KEY_ESC		53
# define KEY_Q			12
# define KEY_W			13
# define KEY_E			14
# define KEY_R			15
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

void		param_init(t_param *param)
{
	param->x = 3;
	param->y = 4;
	param->str[0] = 'a';
	param->str[1] = 'b';
	param->str[2] = '\0';
}

int			key_press(int key_code, t_param	*param)
{
	static int a = 0;

	if (key_code == KEY_W)
		param->x++;
	else if (key_code == KEY_A)
		param->x--;
	else if (key_code == KEY_ESC)
		exit(0);
	else
		printf("x : %d\n", param->x);
	return (0);
}

int main()
{
	void	*mlx;
	void	*win;
	t_param	param;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "mlx_project");
	printf("-------------------------------\n");
	printf("'W key': Add 1 to x.\n");
	printf("'A key': Subtract 1 from x\n");
	printf("'ESC key': Exit this program\n");
	printf("'Other keys': print current x \n");
	printf("-------------------------------\n");
	printf("Current x = 3\n");
	mlx_hook(win, X_EVENT_KEY_PRESS, 0, &key_press, &param);
	mlx_loop(mlx);
}
#include "./includes/fdf.h"

void	moving(int	key, t_arr *arr)
{
	if (key == 126)
		arr->shift_y -= 30;
	else if (key == 125)
		arr->shift_y += 30;
	else if (key == 124)
		arr->shift_x += 30;
	else if (key == 123)
		arr->shift_x -= 30;
	mlx_clear_window(arr->mlx_ptr, arr->win_ptr);
	draw(arr);
}

void	change_zoom(int key, t_arr *arr)
{
	if (key == 24)
		arr->zoom += 2;
	if (key == 27)
		arr->zoom -= 2;
	mlx_clear_window(arr->mlx_ptr, arr->win_ptr);
	draw(arr);
}

void	change_hight(int key, t_arr *arr)
{
	if (key == 116)
		arr->hight += 1;
	if (key == 121)
		arr->hight -= 1;
	mlx_clear_window(arr->mlx_ptr, arr->win_ptr);
	draw(arr);
}

void	close_programm(int	key, t_arr *arr)
{
	write(1, "good bye\n", 9);
	exit (0);
}

void	delete_line(int key, t_arr *arr)
{
	arr->flag_diog = 0;
	mlx_clear_window(arr->mlx_ptr, arr->win_ptr);
	draw(arr);
}

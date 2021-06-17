#include "./includes/fdf.h"

void	create_line(t_arr *arr)
{
	arr->flag_diog = 1;
	mlx_clear_window(arr->mlx_ptr, arr->win_ptr);
	draw(arr);
}

void	create_point(t_arr *arr)
{
	arr->flag_point = 1;
	mlx_clear_window(arr->mlx_ptr, arr->win_ptr);
	draw(arr);
}

void	delete_point(t_arr *arr)
{
	arr->flag_point = 0;
	mlx_clear_window(arr->mlx_ptr, arr->win_ptr);
	draw(arr);
}

void	draw_iso(t_arr *arr)
{
	arr->draw_iso = 1;
	mlx_clear_window(arr->mlx_ptr, arr->win_ptr);
	draw(arr);
}

void	off_iso(t_arr *arr)
{
	arr->draw_iso = 0;
	mlx_clear_window(arr->mlx_ptr, arr->win_ptr);
	draw(arr);
}

#include "./includes/fdf.h"

void	put_point(t_arr *arr, t_point p1, t_point p2)
{
	mlx_pixel_put (arr->mlx_ptr, arr->win_ptr, p1.x, p1.y, p1.color);
	mlx_pixel_put (arr->mlx_ptr, arr->win_ptr, p2.x, p2.y, p2.color);
}

float	mod(float a)
{
	if (a < 0)
		return (a * -1);
	return (a);
}

float	max_mod(float a, float b)
{
	if (mod(a) > mod(b))
		return (mod(a));
	else
		return (mod(b));
}

void	round_y(int key, t_arr *arr)
{
	int		i;
	t_point	tmp;

	mlx_clear_window(arr->mlx_ptr, arr->win_ptr);
	i = 0;
	while (i < arr->size)
	{
		tmp = arr->ptr[i];
		arr->ptr[i].x = tmp.x * cos(0.1) + tmp.z * sin(0.1);
		arr->ptr[i].z = -arr->ptr[i].x * sin(0.1) + arr->ptr[i].z * cos(0.1);
		i++;
	}
	draw(arr);
}

void	round_x(int key, t_arr *arr)
{
	int		i;
	t_point	tmp;

	mlx_clear_window(arr->mlx_ptr, arr->win_ptr);
	i = 0;
	while (i < arr->size)
	{
		tmp = arr->ptr[i];
		arr->ptr[i].y = tmp.y * cos(0.1) + tmp.z * sin(0.1);
		arr->ptr[i].z = -arr->ptr[i].y * sin(0.1) + arr->ptr[i].z * cos(0.1);
		i++;
	}
	draw(arr);
}
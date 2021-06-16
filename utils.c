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

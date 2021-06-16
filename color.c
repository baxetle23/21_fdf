#include "./includes/fdf.h"

int	ft_get_color_by_serg(int i, int r, int g, int b)
{
	return (i << 24 | r << 16 | g << 8 | b);
}

int	get_color(int min, int max, float z)
{
	double	z_otn;

	if (min == max)
		return (0x00ffffff);
	z_otn = (double)(z - min) / (max - min);
	if (z - min > (max - min) / 2 )
		return (ft_get_color_by_serg(0, 255 * z_otn, 255 - 255 * z_otn, 0));
	else
		return (ft_get_color_by_serg(0, 0, 255 * z_otn, 255 - 255 * z_otn));
}

void	get_step(float *x, float *y, t_point p2, t_point p1)
{
	*x = p2.x - p1.x;
	*y = p2.y - p1.y;
}

void	round_(int key, t_arr *arr)
{
	if (key == 15)
		round_y(key, arr);
	if (key == 14)
		round_x(key, arr);
}

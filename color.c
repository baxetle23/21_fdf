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

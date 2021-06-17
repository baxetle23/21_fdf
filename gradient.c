#include "./includes/fdf.h"

float	percent(int start, int end, int current)
{
	float	placement;
	float	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	else
		return (placement / distance);
}

int	get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int	color(t_point start, t_point end, t_point current)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (end.x - start.x > end.y - start.y)
		percentage = percent(start.x, end.x, current.x);
	else
		percentage = percent(start.y, end.y, current.y);
	red = get_light((start.color >> 16) & 0xFF,
			(end.color >> 16) & 0xFF, percentage);
	green = get_light((start.color >> 8) & 0xFF,
			(end.color >> 8) & 0xFF, percentage);
	blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

int	get_new_color(t_arr *arr, float z)
{
	double	z_otn;

	z_otn = (double)(z - arr->zmin) / (arr->zmax - arr->zmin);
	if (arr->color % 4 == 1)
	{
		if (z - arr->zmin > (arr->zmax - arr->zmin) / 2 )
			return (ft_get_color_by_serg(0, 1 * z_otn, 120 - 120 * z_otn, 255));
		else
			return (ft_get_color_by_serg(0, 13 * z_otn, 120 - 13 * z_otn, 13));
	}
	if (arr->color % 4 == 2)
	{
		if (z - arr->zmin > (arr->zmax - arr->zmin) / 2 )
			return (ft_get_color_by_serg(0, 255 * z_otn, 0 - 255 * z_otn, 0));
		else
			return (ft_get_color_by_serg(0, 120 * z_otn, 178 - 1 * z_otn, 255));
	}
	if (arr->color % 4 == 3)
	{
		if (z - arr->zmin > (arr->zmax - arr->zmin) / 2 )
			return (ft_get_color_by_serg(0, 120 * z_otn, 120 - 120 * z_otn, 0));
		else
			return (ft_get_color_by_serg(0, 120 * z_otn, 120 - 120 * z_otn, 0));
	}
	return (0x00ffffff);
}

void	change_color(t_arr *arr)
{
	int		i;

	arr->color++;
	mlx_clear_window(arr->mlx_ptr, arr->win_ptr);
	i = 0;
	while (i < arr->size)
	{	
		if (!(arr->color % 4))
			arr->ptr[i].color = get_color(arr->zmin, arr->zmax, arr->ptr[i].z);
		else
			arr->ptr[i].color = get_new_color(arr, arr->ptr[i].z);
		i++;
	}
	draw(arr);
}

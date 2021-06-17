#include "./includes/fdf.h"

int	deal_key(int key, t_arr	*arr)
{
	if (key == 53)
		close_programm();
	if (key <= 126 && key >= 123)
		moving(key, arr);
	if (key == 24 || key == 27)
		change_zoom(key, arr);
	if (key == 116 || key == 121)
		change_hight(key, arr);
	if (key == 6)
		delete_line(arr);
	if (key == 7)
		create_line(arr);
	if (key == 8)
		create_point(arr);
	if (key == 9)
		delete_point(arr);
	if (key == 34)
		draw_iso(arr);
	if (key == 31)
		off_iso(arr);
	if (key == 15 || key == 14 || key == 13)
		round_(key, arr);
	if (key == 47)
		change_color(arr);
	return (0);
}

void	isometric(t_point *p, t_point *b)
{
	t_point	tmp;

	tmp = *p;
	p->x = (tmp.x - tmp.y) * cos(0.523599);
	p->y = (tmp.x + tmp.y) * sin(0.523599) - tmp.z;
	tmp = *b;
	b->x = (tmp.x - tmp.y) * cos(0.523599);
	b->y = (tmp.x + tmp.y) * sin(0.523599) - tmp.z;
}

void	refresh_flags(t_point *p1, t_point *p2, t_arr *arr)
{
	p1->z *= arr->hight;
	p2->z *= arr->hight;
	p1->x *= arr->zoom;
	p2->x *= arr->zoom;
	p1->y *= arr->zoom;
	p2->y *= arr->zoom;
	p1->x += arr->shift_x;
	p2->x += arr->shift_x;
	p1->y += arr->shift_y;
	p2->y += arr->shift_y;
}

void	draw_line(t_point p1, t_point p2, t_arr *arr)
{
	t_point	start;
	float	x_step;
	float	y_step;
	float	max;

	refresh_flags(&p1, &p2, arr);
	if (arr->draw_iso == 1)
		isometric(&p1, &p2);
	start = p1;
	get_step(&x_step, &y_step, p2, p1);
	max = max_mod(x_step, y_step);
	x_step /= max;
	y_step /= max;
	if (arr->flag_point)
		put_point(arr, p1, p2);
	else
	{	
		while ((int)(p1.x - p2.x) || (int)(p1.y - p2.y))
		{
			mlx_pixel_put(arr->mlx_ptr, arr->win_ptr, p1.x, p1.y,
				color(start, p2, p1));
			p1.x += x_step;
			p1.y += y_step;
		}
	}
}

void	draw(t_arr *arr)
{
	int	i;

	i = 0;
	while (i < arr->size)
	{
		if (i % arr->num_in_line != arr->num_in_line - 1)
			draw_line(arr->ptr[i], arr->ptr[i + 1], arr);
		if (i < arr->size - arr->num_in_line)
		{
			draw_line(arr->ptr[i], arr->ptr[i + arr->num_in_line], arr);
			if (i % arr->num_in_line != arr->num_in_line - 1 && arr->flag_diog)
				draw_line(arr->ptr[i], arr->ptr[i + arr->num_in_line + 1], arr);
		}
		i++;
	}
	mlx_key_hook(arr->win_ptr, deal_key, arr);
	mlx_loop(arr->mlx_ptr);
}

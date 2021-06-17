#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include "./get_next_line.h"

# define HEIGHT 1500
# define WIDTH 1500

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
}			t_point;

typedef struct s_arr
{
	int		size;
	int		lines;
	int		num_in_line;
	int		zoom;
	int		shift_x;
	int		shift_y;
	int		hight;
	int		zmax;
	int		zmin;
	int		flag_diog;
	int		flag_point;
	int		draw_iso;
	int		povorot_y;
	int		color;
	t_point	*ptr;

	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	void	*mlx_ptr;
	void	*win_ptr;
}			t_arr;

void	ReadFile(char *file_name, t_arr *arr);
void	draw(t_arr *arr);

void	init_flags(t_arr *arr);
void	found_min_max(t_arr *arr);

void	moving(int	key, t_arr *arr);
void	change_zoom(int key, t_arr *arr);
void	change_hight(int key, t_arr *arr);
void	close_programm(void);
void	delete_line(t_arr *arr);
void	create_line(t_arr *arr);
void	create_point(t_arr *arr);
void	draw_iso(t_arr *arr);
void	delete_point(t_arr *arr);
void	off_iso(t_arr *arr);

void	put_point(t_arr *arr, t_point p1, t_point p2);
float	max_mod(float a, float b);

int		ft_get_color_by_serg(int i, int r, int g, int b);
int		get_color(int min, int max, float z);
int		color(t_point start, t_point end, t_point current);
void	round_(int key, t_arr *arr);
void	round_x(t_arr *arr);
void	round_y(t_arr *arr);
void	change_color(t_arr *arr);
void	get_step(float *x, float *y, t_point p2, t_point p1);

#endif

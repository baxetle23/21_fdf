#include "./includes/fdf.h"

int	main(int argc, char **argv)
{
	t_arr	arr;

	if (argc == 2)
	{
		ReadFile(argv[1], &arr);
		arr.mlx_ptr = mlx_init();
		arr.win_ptr = mlx_new_window(arr.mlx_ptr, HEIGHT, WIDTH, "ALPO");
		draw(&arr);
		free(arr.ptr);
	}
	return (0);
}

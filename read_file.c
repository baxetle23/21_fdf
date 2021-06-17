#include "./includes/fdf.h"

int	get_data(t_point *data, char *line, int y)
{
	static int	i = 0;

	while (*line != '\0')
	{
		data[i].z = ft_atoi(line);
		data[i].y = (y - 2);
		data[i].x = i;
		i++;
		while (*line == ' ' || *line == '-')
			line++;
		while (ft_isdigit((*line)))
			line++;
		if (*line == ',')
		{
			while (*line != ' ' && *line != '\0')
				line++;
		}
		while (*line == ' ')
			line++;
		if (*line == '\0')
			break ;
	}
	return (i);
}

void	ReadFile(char *file_name, t_arr *arr)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit (1);
	arr->lines = 1;
	arr->ptr = (t_point *)malloc(sizeof(t_point) * 1000000);
	if (arr->ptr == NULL)
		exit (1);
	while (get_next_line(fd, &line))
	{
		arr->lines++;
		get_data(arr->ptr, line, arr->lines);
		if (ft_strlen(line) == 0)
			arr->lines--;
		free (line);
	}
	arr->size = get_data(arr->ptr, line, arr->lines);
	if (ft_strlen(line) == 0)
		arr->lines--;
	free (line);
	found_min_max(arr);
	init_flags(arr);
}

void	found_min_max(t_arr *arr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	arr->zmax = arr->ptr[0].z;
	arr->zmin = arr->ptr[0].z;
	while (i < arr->size)
	{
		arr->ptr[i].x = j;
		j++;
		if (arr->ptr[i].z > arr->zmax)
			arr->zmax = arr->ptr[i].z;
		if (arr->ptr[i].z < arr->zmin)
			arr->zmin = arr->ptr[i].z;
		if ((i + 1) % (arr->size / arr->lines) == 0 && i != 0)
			j = 0;
		i++;
	}
}

void	init_flags(t_arr *arr)
{
	int	i;

	i = 0;
	while (i < arr->size)
	{
		arr->ptr[i].color = get_color(arr->zmin, arr->zmax, arr->ptr[i].z);
		i++;
	}
	arr->num_in_line = arr->size / arr->lines;
	arr->shift_x = 0;
	arr->shift_y = 0;
	arr->zoom = 30;
	arr->hight = 1;
	arr->draw_iso = 0;
	arr->povorot_y = 0;
	arr->color = 0;
}

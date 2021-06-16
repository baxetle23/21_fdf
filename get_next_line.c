#include "./includes/fdf.h"

char	*ft_strjoin_mod(char *s1, char *s2)
{
	char	*new_string;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	new_string = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_string)
		return (NULL);
	while (s1[i] != '\0')
	{
		new_string[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		new_string[i] = s2[j];
		i++;
		j++;
	}
	free(s1);
	new_string[i] = '\0';
	return (new_string);
}

char	*check_reminder(char **reminder, char **line)
{
	char	*pointer_n;

	pointer_n = NULL;
	if (*reminder)
	{
		pointer_n = ft_strchr(*reminder, '\n');
		if (pointer_n)
		{
			*pointer_n++ = '\0';
			*line = ft_strdup(*reminder);
			ft_memmove(*reminder, pointer_n, ft_strlen(pointer_n));
		}
		else
		{
			*line = ft_strdup(*reminder);
			ft_strclr(*reminder);
		}
	}
	else
		*line = ft_strdup("");
	return (pointer_n);
}

int	read_file(int fd, int *last_byte, char **buffer)
{
	*last_byte = read(fd, *buffer, BUFFER_SIZE);
	if (*last_byte)
		return (1);
	return (0);
}

int	get_memory(int fd, char **line, char **buffer)
{
	if (BUFFER_SIZE < 1 || fd < 0 || fd > 999 || !line || read(fd, 0, 0) < 0)
		return (1);
	*buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!(*buffer))
		return (1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	t_gnl		gnl;
	static char	*reminder;

	if (get_memory(fd, line, &(gnl.buffer)))
		return (-1);
	gnl.pointer_n = check_reminder(&reminder, line);
	while ((!(gnl.pointer_n) && (read_file(fd, &(gnl.byte), &(gnl.buffer)))))
	{
		(gnl.buffer)[gnl.byte] = '\0';
		gnl.pointer_n = ft_strchr(gnl.buffer, '\n');
		if (gnl.pointer_n)
		{
			*(gnl.pointer_n)++ = '\0';
			if (reminder)
				free(reminder);
			reminder = ft_strdup(gnl.pointer_n);
		}
		*line = ft_strjoin_mod(*line, gnl.buffer);
	}
	free(gnl.buffer);
	if (gnl.pointer_n || ft_strlen(reminder))
		return (1);
	free(reminder);
	reminder = NULL;
	return (0);
}

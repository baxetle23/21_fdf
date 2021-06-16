#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define BUFFER_SIZE 1024000

typedef struct s_gnl
{
	int		byte;
	char	*pointer_n;
	char	*buffer;
}			t_gnl;

int		get_next_line(int fd, char **line);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strchr(const char *s, int c);
void	ft_strclr(char *s);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);

#endif

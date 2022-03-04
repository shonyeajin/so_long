#include "libft.h"

static int check_newline(char **line, char **dummy, char **buf)
{
	char *str;
	char *p;

	str = *dummy;
	if (!(p = ft_strchr(*dummy, '\n')))
	{
		if (!*dummy)
			*line = ft_strndup("", 1);
		else
			*line = *dummy;
		*dummy = 0;
		free(*buf);
		return (0);
	}
	*line = ft_strndup(str, p - str);
	*dummy = ft_strndup(p + 1, BUFFER_SIZE);
	free(str);
	free(*buf);
	return (1);
}

static void ft_concatenate(char **dummy, char **buf, int ret)
{
	char *temp;

	if (!*dummy)
	{
		free(*dummy);
		*dummy = ft_strndup(*buf, ret);
	}
	else
	{
		temp = *dummy;
		*dummy = ft_strjoin(temp, *buf);
		free(temp);
	}
}

int get_next_line(int fd, char **line)
{
	static char *dummy;
	char *buf;
	int ret;

	if (!line || BUFFER_SIZE <= 0 || fd < 0 || fd > OPEN_MAX - 1 || !(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!(ft_strchr(dummy, '\n')) && (ret = read(fd, buf, BUFFER_SIZE)) != 0)
	{
		if (ret == -1)
		{
			free(buf);
			return(-1);
		}
		buf[ret] = '\0';
		ft_concatenate(&dummy, &buf, ret);
	}
	return (check_newline(line, &dummy, &buf));
}

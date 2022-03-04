#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# define OPEN_MAX 256
# define BUFFER_SIZE 1024

int get_next_line(int fd, char **line);
size_t ft_strlen(const char *s);
char *ft_strndup(const char *s1, size_t n);
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strchr(const char *s, int c);
#endif

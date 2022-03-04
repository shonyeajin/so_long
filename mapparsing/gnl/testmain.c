#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	/*
	int fd;
	char **p;

	p=(char **)malloc(sizeof(char *));
	if ((fd=open("text.txt", O_RDONLY))==-1)
		printf("open error\n");
	get_next_line(fd, p);
	printf("%s\n", (char *)*p);
	get_next_line(fd, p);
	printf("%s\n", (char *)*p);
	get_next_line(fd, p);
	printf("%s\n", (char *)*p);
	get_next_line(fd, p);
	printf("%s\n", (char *)*p);
	get_next_line(fd, p);
	printf("%s\n", (char *)*p);

	close(fd);

	*/

	int fd;
	char *p;
	if ((fd=open("text.txt", O_RDONLY))==-1)
		printf("open error\n");
	get_next_line(fd, &p);
	get_next_line(fd, &p);
	get_next_line(fd, &p);
	get_next_line(fd, &p);
	get_next_line(fd, &p);

	if (!*p)
		printf("it is null\n");
	close(fd);

}

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a
SOURCES = ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c get_next_line.c get_next_line_utils.c
OBJECTS = $(SOURCES:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJECTS)
	ar -cr $@ $^

clean :
	rm -rf $(OBJECTS)

fclean : clean
	rm -rf $(NAME)

re : clean all

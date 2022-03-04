CC = gcc
NAME=gnl.a
SOURCES = get_next_line.c get_next_line_utils.c
OBJECTS=$(SOURCES:.c=.o)

all : $(NAME)

%.o : %.c
		$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJECTS)
		ar -cr $@ $^

clean :
		rm -f $(OBJECTS)

fclean : clean
		rm -f $(NAME)

re : clean all


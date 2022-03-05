NAME = so_long
SRCS= main.c
OBJS=$(SRCS:%.c=%.o)
LIBFT = libft

CC=clang
CFLAGS= -Wall -Werror -Wextra -g3 -fsanitize=address
CLIB = -Lminilibx_opengl_20191021 -lmlx -framework OpenGL -framework Appkit -Imlx

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(MAKE) all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT).a $(LIBFT).a
	$(CC) $(CFLAGS) $(CLIB) $(SRCS) libft.a -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all


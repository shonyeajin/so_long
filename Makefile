NAME = so_long
SRCS= main.c
OBJS=$(SRCS:%.c=%.o)
LIBFT = libft

CC=clang
CFLAGS= -Wall -Werror -Wextra -g3 -fsanitize=address
CLIB = -Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(MAKE) all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT).a $(LIBFT).a
	$(CC) $(CFLAGS) $(CLIB) $(SRCS) libft.a -o $(NAME)
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all


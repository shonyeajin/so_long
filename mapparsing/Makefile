NAME= a.out
SRCS= main.c
OBJS= $(SRCS:%.c=%.o)

all : $(NAME)

%.o : %.c
			gcc -c $< -o $@

$(NAME) : $(OBJS)
			$(MAKE) all -C gnl/
			cp gnl/gnl.a gnl.a
			gcc $(SRCS) gnl.a -o $(NAME)

clean:
			rm -rf $(OBJS)

fclean: clean
			rm -rf $(NAME)

re: fclean all

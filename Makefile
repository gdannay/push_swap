NAME	=	checker

SRCS	=	srcs_c/checker.c		\
			srcs_c/manage_args.c	\
			srcs_c/manage_lst.c		\
			srcs_c/get_com.c		\
			srcs_c/commands.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra -I./includes -I./libft

LFLAGS	=	libft/libft.a

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			make -C libft
			$(CC) $(OBJS) $(LFLAGS) -o $(NAME)

%.o		:	%.c
			$(CC) -o $@ -c $< $(CFLAGS)

clean	:
			make clean -C libft
			rm -rf $(OBJS)

fclean	:
			make fclean -C libft
			rm -rf $(OBJS)
			rm -rf $(NAME)

re		:	fclean all

NAME		=	checker

NAME2		=	push_swap

SRCS		=	srcs/manage_args.c	\
				srcs/manage_lst.c	\
				srcs/get_com.c		\
				srcs/commands.c		\
				srcs/algo.c

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra -I./includes -I./libft

LFLAGS		=	libft/libft.a

all			:	$(NAME) $(NAME2)

$(NAME)		:	$(OBJS) checker.o
				make -C libft
				$(CC) $(OBJS) checker.o $(LFLAGS) -o $(NAME)

$(NAME2)	:	$(OBJS) push_swap.o
				$(CC) $(OBJS) push_swap.o $(LFLAGS) -o $(NAME2)

push_swap.o	:	srcs/push_swap.c
				$(CC) -o $@ -c $< $(CFLAGS)

checker.o	:	srcs/checker.c
				$(CC) -o $@ -c $< $(CFLAGS)

%.o			:	%.c
				$(CC) -o $@ -c $< $(CFLAGS)

clean		:
				make clean -C libft
				rm -rf $(OBJS)

fclean		:
				make fclean -C libft
				rm -rf $(OBJS)
				rm -rf $(NAME)

re			:	fclean all

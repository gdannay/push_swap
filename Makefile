# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdannay <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/08 17:11:07 by gdannay           #+#    #+#              #
#    Updated: 2018/01/15 18:30:45 by gdannay          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	checker

NAME2		=	push_swap

SRCS		=	srcs/manage_args.c		\
				srcs/manage_lst.c		\
				srcs/get_com.c			\
				srcs/commands.c			\
				srcs/algo.c				\
				srcs/algobig.c			\
				srcs/algosmall.c		\
				srcs/manage_commands.c	\
				srcs/computation.c		\
				srcs/fusion.c

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra -I./includes -I./libft

LFLAGS		=	libft/libft.a -g3 -fsanitize=address

all			:	$(NAME) $(NAME2)

$(NAME)		:	$(OBJS) srcs/checker.o
				make -C libft
				$(CC) $(OBJS) srcs/checker.o $(LFLAGS) -o $(NAME)

$(NAME2)	:	$(OBJS) srcs/push_swap.o
				$(CC) $(OBJS) srcs/push_swap.o $(LFLAGS) -o $(NAME2)

srcs/push_swap.o	:	srcs/push_swap.c
				$(CC) -o $@ -c $< $(CFLAGS)

srcs/checker.o	:	srcs/checker.c
				$(CC) -o $@ -c $< $(CFLAGS)

%.o			:	%.c
				$(CC) -o $@ -c $< $(CFLAGS)

clean		:
				make clean -C libft
				rm -rf $(OBJS)
				rm -rf srcs/checker.o
				rm -rf srcs/push_swap.o

fclean		:
				make fclean -C libft
				rm -rf srcs/checker.o
				rm -rf srcs/push_swap.o
				rm -rf $(OBJS)
				rm -rf $(NAME2)
				rm -rf $(NAME)

re			:	fclean all

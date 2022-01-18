# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 10:57:28 by hhamdy            #+#    #+#              #
#    Updated: 2021/12/21 16:46:58 by hhamdy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC     	= 	gcc

CFLAGS 	= 	-Wall -Wextra -Werror

NAME 	=	push_swap

LIBFT	=	libft/libft.a

SRCS 	=  	push_swap.c	\
			ft_check_error.c \
			operation.c \
			ft_sort.c \
			do_instraction.c \
			sort_small_stack.c \

OBJS	= $(SRCS:.c=.o)
	
all:	$(NAME)

$(NAME):	$(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

$(LIBFT):
	make -C libft

clean:
	make clean -C libft
	rm -rf $(OBJS)

fclean: clean
	rm -rf libft/libft.a
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jesse <jesse@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 10:57:28 by hhamdy            #+#    #+#              #
#    Updated: 2022/01/27 10:47:50 by jesse            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC     	= 	gcc

CFLAGS 	= 	-Wall -Wextra -Werror

NAME 	=	push_swap

CHECKER =	checker

LIBFT	=	libft/libft.a

SRCS 	=  	push_swap.c	\
			ft_check_error.c \
			instractions.c \
			ft_sort.c \
			do_instractions.c \
			sort_small_stack.c \
			ft_utils.c

OBJS	= $(SRCS:.c=.o)

B_SRCS =	ft_checker/get_next_line.c \
			ft_checker/get_next_line_utils.c \
			ft_checker/checker_utils.c \
			checker.c \
			ft_check_error.c \
			do_instractions.c \
			instractions.c \
			ft_utils.c
			

B_OBJS	= $(B_SRCS:.c=.o)
	
all:	$(NAME)

$(NAME):	$(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

bonus: $(CHECKER)

$(CHECKER):   $(B_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(B_OBJS) -o $(CHECKER) $(LIBFT)

$(LIBFT):
	make -C libft

clean:
	make clean -C libft
	rm -rf $(OBJS)
	rm -rf $(B_OBJS)

fclean: clean
	rm -rf libft/libft.a
	rm -rf $(NAME)
	rm -rf $(CHECKER)

re: fclean all

.PHONY: all clean fclean re
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 09:25:42 by jesse             #+#    #+#             */
/*   Updated: 2022/01/28 13:09:12 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_list *stack_a, t_list *stack_b, char *str)
{
	if (!ft_strcmp(str, "sa\n"))
		ft_swap(stack_a);
	else if (!ft_strcmp(str, "sb\n"))
		ft_swap(stack_b);
	else if (!ft_strcmp(str, "ss\n"))
	{
		ft_swap(stack_a);
		ft_swap(stack_b);
	}
}

static void	push(t_list **stack_a, t_list **stack_b, char *str)
{
	if (!ft_strcmp(str, "pa\n"))
		ft_push(stack_b, stack_a);
	else if (!ft_strcmp(str, "pb\n"))
		ft_push(stack_a, stack_b);
}

static void	rotate(t_list **stack_a, t_list **stack_b, char *str)
{
	if (!ft_strcmp(str, "ra\n"))
		ft_rotate(stack_a);
	else if (!ft_strcmp(str, "rb\n"))
		ft_rotate(stack_b);
	else if (!ft_strcmp(str, "rr\n"))
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
	}
}

static void	rev_rotate(t_list **stack_a, t_list **stack_b, char *str)
{
	if (!ft_strcmp(str, "rra\n"))
		ft_rev_rotate(stack_a);
	else if (!ft_strcmp(str, "rrb\n"))
		ft_rev_rotate(stack_b);
	else if (!ft_strcmp(str, "rrr\n"))
	{
		ft_rev_rotate(stack_a);
		ft_rev_rotate(stack_b);
	}
}

void	check_instraction(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!ft_strcmp(line, "sa\n") || !ft_strcmp(line, "sb\n")
			|| !ft_strcmp(line, "ss\n"))
			swap(*stack_a, *stack_b, line);
		else if (!ft_strcmp(line, "pa\n") || !ft_strcmp(line, "pb\n"))
			push(stack_a, stack_b, line);
		else if (!ft_strcmp(line, "ra\n") || !ft_strcmp(line, "rb\n")
			|| !ft_strcmp(line, "rr\n"))
			rotate(stack_a, stack_b, line);
		else if (!ft_strcmp(line, "rra\n") || !ft_strcmp(line, "rrb\n")
			|| !ft_strcmp(line, "rrr\n"))
			rev_rotate(stack_a, stack_b, line);
		else
			write (2, "Error\n", 6);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(*stack_a))
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
}

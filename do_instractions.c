/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_instractions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:55:00 by hhamdy            #+#    #+#             */
/*   Updated: 2022/01/28 01:16:41 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_write(char *str)
{
	write (1, str, ft_strlen(str));
	write (1, "\n", 1);
}

int	do_swap(t_list *stack_a, t_list *stack_b, char *str)
{
	if (!ft_strcmp(str, "sa"))
		ft_swap(stack_a);
	else if (!ft_strcmp(str, "sb"))
		ft_swap(stack_b);
	else if (!ft_strcmp(str, "ss"))
	{
		ft_swap(stack_a);
		ft_swap(stack_b);
	}
	else
		return (0);
	ft_write(str);
	return (1);
}

int	do_push(t_list **stack_a, t_list **stack_b, char *str)
{
	if (!ft_strcmp(str, "pa"))
		ft_push(stack_b, stack_a);
	else if (!ft_strcmp(str, "pb"))
		ft_push(stack_a, stack_b);
	else
		return (0);
	ft_write (str);
	return (1);
}

int	do_rotate(t_list **stack_a, t_list **stack_b, char *str)
{
	if (!ft_strcmp(str, "ra"))
		ft_rotate(stack_a);
	else if (!ft_strcmp(str, "rb"))
		ft_rotate(stack_b);
	else if (!ft_strcmp(str, "rr"))
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
	}
	else
		return (0);
	ft_write (str);
	return (1);
}

int	do_rev_rotate(t_list **stack_a, t_list **stack_b, char *str)
{
	if (!ft_strcmp(str, "rra"))
		ft_rev_rotate(stack_a);
	else if (!ft_strcmp(str, "rrb"))
		ft_rev_rotate(stack_b);
	else if (!ft_strcmp(str, "rrr"))
	{
		ft_rev_rotate(stack_a);
		ft_rev_rotate(stack_b);
	}
	else
		return (0);
	ft_write(str);
	return (1);
}

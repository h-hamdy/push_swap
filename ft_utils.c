/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:32:08 by hhamdy            #+#    #+#             */
/*   Updated: 2022/02/08 11:32:13 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check if the linked list is sorted
int	is_sorted(t_list *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->content > stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

// this function return the small number in the linked list
int	get_min(t_list **stack_a)
{
	int		min;
	t_list	*tmp;

	min = (*stack_a)->content;
	tmp = *stack_a;
	while (tmp)
	{
		if (min > tmp->content)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

// get the position of the small number in stack_a
int	get_count(t_list **stack_a)
{
	t_list	*tmp;
	int		min;
	int		count;

	count = 0;
	tmp = *stack_a;
	min = get_min(stack_a);
	while (tmp)
	{
		if (tmp->content == min)
			break ;
		tmp = tmp->next;
		count++;
	}
	return (count);
}

// set-up the args in linked list
t_list	*ft_set_stack(int ac, char **av)
{
	t_list	*stack;
	t_list	*buff;
	int		i;

	i = 1;
	stack = NULL;
	buff = NULL;
	while (i <= ac)
	{
		buff = ft_lstnew(ft_atoi(av[i]));
		if (!buff)
			exit (1);
		ft_lstadd_back(&stack, buff);
		i++;
	}
	return (stack);
}

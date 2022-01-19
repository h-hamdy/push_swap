/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 08:01:31 by hhamdy            #+#    #+#             */
/*   Updated: 2021/12/23 08:47:36 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_tree(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->content > (*stack_a)->next->next->content)
		do_rotate(stack_a, stack_b, "ra");
	else if ((*stack_a)->next->content > (*stack_a)->content
		&& (*stack_a)->next->content > (*stack_a)->next->next->content)
		do_rev_rotate(stack_a, stack_b, "rra");
	if ((*stack_a)->content > (*stack_a)->next->content)
		do_swap(*stack_a, *stack_b, "sa");
}

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

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	int	count;

	count = get_count(stack_a);
	if (count == 0)
		do_push(stack_a, stack_b, "pb");
	if (count == 1)
	{
		do_swap(*stack_a, *stack_b, "sa");
		do_push(stack_a, stack_b, "pb");
	}
	if (count == 2)
	{
		do_rotate(stack_a, stack_b, "ra");
		do_rotate(stack_a, stack_b, "ra");
		do_push(stack_a, stack_b, "pb");
	}
	if (count == 3)
	{
		do_rev_rotate(stack_a, stack_b, "rra");
		do_push(stack_a, stack_b, "pb");
	}
	sort_tree(stack_a, stack_b);
	do_push(stack_a, stack_b, "pa");
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	count;

	count = get_count(stack_a);
	if (count == 0)
		do_push(stack_a, stack_b, "pb");
	if (count == 1)
	{
		do_swap(*stack_a, *stack_b, "sa");
		do_push(stack_a, stack_b, "pb");
	}
	if (count == 2)
	{
		do_rotate(stack_a, stack_b, "ra");
		do_rotate(stack_a, stack_b, "ra");
		do_push(stack_a, stack_b, "pb");
	}
	if (count == 3)
	{
		do_rev_rotate(stack_a, stack_b, "rra");
		do_rev_rotate(stack_a, stack_b, "rra");
		do_push(stack_a, stack_b, "pb");
	}
	if (count == 4)
	{
		do_rev_rotate(stack_a, stack_b, "rra");
		do_push(stack_a, stack_b, "pb");
	}
}

void	sort_small_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			do_swap((*stack_a), (*stack_b), "sa");
	}
	if (ft_lstsize(*stack_a) == 3)
		sort_tree(stack_a, stack_b);
	if (ft_lstsize(*stack_a) == 4)
		sort_four(stack_a, stack_b);
	if (ft_lstsize(*stack_a) == 5)
	{
		sort_five(stack_a, stack_b);
		sort_four(stack_a, stack_b);
		do_push(stack_a, stack_b, "pa");
	}
	// printf("-----LINKED LIST SORTED---------------\n");
	// while (*stack_a)
	// {
	// 	printf("%d\n", (*stack_a)->content);
	// 	(*stack_a) = (*stack_a)->next;
	// }
}

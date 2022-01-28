/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:24:37 by hhamdy            #+#    #+#             */
/*   Updated: 2022/01/27 17:11:00 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sort numbers greater than 5
void	sort_big_stack(t_list **stack_a, t_list **stack_b)
{
	int	index;
	int	i;
	int	len_stack;

	index = 0;
	len_stack = ft_lstsize(*stack_a);
	while (!is_sorted(*stack_a))
	{
		i = 0;
		while (i < len_stack)
		{
			if ((((*stack_a)->content >> index) & 1) == 0)
			{
				do_push(stack_a, stack_b, "pb");
			}
			else if ((((*stack_a)->content >> index) & 1) == 1)
			{
				do_rotate(stack_a, stack_b, "ra");
			}
			i++;
		}
		while (*stack_b)
			do_push(stack_a, stack_b, "pa");
		index++;
	}
}

// Convert the stack_a to a index from the sorted array
void	get_index(t_list **stack_a, int *tab)
{
	int		i;
	t_list	*tmp;

	tmp = *stack_a;
	while ((*stack_a))
	{
		i = 0;
		while ((*stack_a)->content != tab[i])
			i++;
		if ((*stack_a)->content == tab[i])
			(*stack_a)->content = i;
		(*stack_a) = (*stack_a)->next;
	}
	*stack_a = tmp;
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*sort_stack;

	stack_b = NULL;
	if (ac <= 2)
		return (0);
	ft_check_error(ac, av);
	stack_a = ft_set_stack(ac - 1, av);
	if (is_sorted(stack_a) == 1)
		exit(0);
	if (ft_lstsize(stack_a) <= 5)
		sort_small_stack(&stack_a, &stack_b);
	sort_stack = buble_sort(stack_a, ac - 1);
	get_index(&stack_a, sort_stack);
	sort_big_stack(&stack_a, &stack_b);
}

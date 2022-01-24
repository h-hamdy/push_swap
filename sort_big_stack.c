/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:52:53 by jesse             #+#    #+#             */
/*   Updated: 2022/01/24 19:07:00 by jesse            ###   ########.fr       */
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

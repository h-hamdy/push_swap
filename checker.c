/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesse <jesse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 09:42:36 by jesse             #+#    #+#             */
/*   Updated: 2022/01/28 12:58:19 by jesse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	if (ac <= 2)
		return (0);
	ft_check_error(ac, av);
	stack_a = ft_set_stack(ac - 1, av);
	check_instraction(&stack_a, &stack_b);
	while (stack_a)
	{
		printf("stack a = %d\n", stack_a->content);
		stack_a = stack_a->next;
	}
	return (0);
}

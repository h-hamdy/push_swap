/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:31:14 by hhamdy            #+#    #+#             */
/*   Updated: 2022/02/08 11:31:37 by hhamdy           ###   ########.fr       */
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
	return (0);
}

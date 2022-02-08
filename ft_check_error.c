/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 09:53:12 by hhamdy            #+#    #+#             */
/*   Updated: 2022/02/08 10:29:32 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check if there are duplicates
static int	ft_check_double(int n, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

// check if there is no numbers | or one of the numbers is > | < than int
void	ft_check_error(int count, char **str)
{
	int	i;

	i = 1;
	if (!ft_check_double(count, str))
	{
		write (2, "Error\n", 6);
		exit (1);
	}
	while (i < count)
	{
		if (ft_atoi(str[i]) > INT_MAX || ft_atoi(str[i]) < INT_MIN)
		{
			write (2, "Error\n", 6);
			exit (1);
		}
		i++;
	}
}

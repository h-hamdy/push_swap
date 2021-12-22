/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 09:53:49 by hhamdy            #+#    #+#             */
/*   Updated: 2021/12/22 10:15:08 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*alloc_tab(t_list *list, int n)
{
	int	i;
	int	*tab;

	i = 0;
	tab = (int *)malloc(sizeof(int) * n);
	if (!tab)
		return (0);
	while (list && i < n)
	{
		tab[i] = list->content;
		list = list->next;
		i++;
	}
	tab[i] = 0;
	return (tab);
}

void	swap(int *num1, int *num2)
{
	int	swp;

	swp = *num1;
	*num1 = *num2;
	*num2 = swp;
}

int	*buble_sort(t_list *list, int n) 
{
	int		*tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab = alloc_tab(list, n);
	while (i < n)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (tab[j] > tab[j + 1])
				swap(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
	return (tab);
}

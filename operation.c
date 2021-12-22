/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 11:59:51 by hhamdy            #+#    #+#             */
/*   Updated: 2021/12/20 11:32:35 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list *head)
{
	t_list	*tmp;
	int		swp;

	tmp = head;
	tmp = tmp->next;
	swp = head->content;
	head->content = tmp->content;
	tmp->content = swp;
}

void	ft_push(t_list **src, t_list **dest)
{
	t_list	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	ft_lstadd_front(dest, tmp);
}

void	ft_rotate(t_list **head)
{
	t_list	*tmp;
	t_list	*last;

	if (ft_lstsize(*head) < 2)
		return ;
	tmp = (*head);
	(*head) = (*head)->next;
	last = ft_lstlast(*head);
	last->next = tmp;
	tmp->next = NULL;
}

void	ft_rev_rotate(t_list **head)
{
	t_list	*tmp;
	t_list	*prelast;

	prelast = *head;
	if (ft_lstsize(*head) < 2)
		return ;
	tmp = ft_lstlast(*head);
	while (prelast->next->next)
		prelast = prelast->next;
	prelast->next = NULL;
	ft_lstadd_front(head, tmp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 09:57:38 by hhamdy            #+#    #+#             */
/*   Updated: 2021/12/23 08:38:54 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft/libft.h"

/*________________ERROR-HANDLING________________*/
void		ft_check_error(int count, char **str);

/*_________________INSTRACTION______________________*/
void		ft_swap(t_list *head);
void		ft_push(t_list **src, t_list **dest);
void		ft_rotate(t_list **head);
void		ft_rev_rotate(t_list **head);

/*_________________DO_INSTRACTION_____________________*/
int			do_swap(t_list *stack_a, t_list *stack_b, char *str);
int			do_push(t_list **stack_a, t_list **stack_b, char *str);
int			do_rotate(t_list **stack_a, t_list **stack_b, char *str);
int			do_rev_rotate(t_list **stack_a, t_list **stack_b, char *str);

/*_________________SORTING_ACTION____________________*/
int			*buble_sort(t_list *list, int ac);
void		sort_small_stack(t_list **stack_a, t_list **stack_b);

/*____________________PUSH_SWAP__________________*/
t_list		**push_swap(int n, char **stack);

#endif

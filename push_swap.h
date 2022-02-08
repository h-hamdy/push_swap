/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:32:40 by hhamdy            #+#    #+#             */
/*   Updated: 2022/02/08 11:32:42 by hhamdy           ###   ########.fr       */
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
t_list		*ft_set_stack(int ac, char **av);
int			is_sorted(t_list *stack_a);
int			get_min(t_list **stack_a);
int			get_count(t_list **stack_a);

/*__________________BONUS-PART_______________________*/

# define BUFFER_SIZE 1024

char		*get_next_line(int fd);
size_t		ft_strlen(const char *str);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *s, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s1);
void		check_instraction(t_list **stack_a, t_list **stack_b);

#endif

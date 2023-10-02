/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <agomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 08:24:40 by agomes-g          #+#    #+#             */
/*   Updated: 2023/06/15 12:40:09 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_a(t_list **a)
{
	t_list	*last;
	t_list	*tmp;

	last = ft_lstlast(*a);
	tmp = *a;
	if (!tmp || !tmp->next)
		return ;
	while (tmp->next != last)
		tmp = tmp->next;
	tmp->next = NULL;
	last->next = *a;
	*a = last;
	ft_printf("rra\n");
}

void	rev_b(t_list **a)
{
	t_list	*last;
	t_list	*tmp;

	last = ft_lstlast(*a);
	tmp = *a;
	if (!tmp || !tmp->next)
		return ;
	while (tmp->next != last)
		tmp = tmp->next;
	tmp->next = NULL;
	last->next = *a;
	*a = last;
	ft_printf("rrb\n");
}

void	rrr(t_list **a, t_list **b)
{
	rev_a(a);
	rev_b(b);
}

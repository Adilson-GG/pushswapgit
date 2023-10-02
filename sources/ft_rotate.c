/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <agomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 08:24:24 by agomes-g          #+#    #+#             */
/*   Updated: 2023/06/15 12:40:48 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **a)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *a;
	last = ft_lstlast(*a);
	*a = (*a)->next;
	tmp->next = NULL;
	last->next = tmp;
	ft_printf("ra\n");
}

void	rotate_b(t_list **a)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *a;
	last = ft_lstlast(*a);
	*a = (*a)->next;
	tmp->next = NULL;
	last->next = tmp;
	ft_printf("rb\n");
}

void	rr(t_list **a, t_list **b)
{
	rotate_a(a);
	rotate_b(b);
}

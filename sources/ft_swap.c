/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <agomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:54:06 by agomes-g          #+#    #+#             */
/*   Updated: 2023/06/14 08:47:22 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **a)
{
	t_list	*tmp;

	if (!(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	ft_printf("sa\n");
}

void	swap_b(t_list **a)
{
	t_list	*tmp;

	if (!(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	ft_printf("sb\n");
}

void	ss(t_list **a, t_list **b)
{
	swap_a(a);
	swap_b(b);
}

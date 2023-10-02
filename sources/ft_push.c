/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <agomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 08:24:13 by agomes-g          #+#    #+#             */
/*   Updated: 2023/06/15 12:40:00 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list **from, t_list **to)
{
	t_list	*tmp;

	if (from)
	{
		ft_printf("pa\n");
		tmp = *from;
		*from = (*from)->next;
		ft_lstadd_front(to, tmp);
	}
}

void	push_b(t_list **from, t_list **to)
{
	t_list	*tmp;

	if (from)
	{
		ft_printf("pb\n");
		tmp = *from;
		*from = (*from)->next;
		ft_lstadd_front(to, tmp);
	}
}

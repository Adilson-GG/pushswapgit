/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <agomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 10:53:18 by agomes-g          #+#    #+#             */
/*   Updated: 2023/09/19 07:26:50 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Prends l'element choisi pour le placer en tete de la liste A

void	be_first(t_list **a, t_list *tmp)
{
	t_list	*temp;
	int		i;

	temp = *a;
	i = 0;
	while (compare_str(temp->content, tmp->content) != 0)
	{
		temp = temp->next;
		i ++;
	}
	if (i == 1)
		swap_a(a);
	else if (i < ft_lstsize(*a) / 2)
	{
		while (i--)
			rotate_a(a);
	}
	else
	{
		while (ft_lstsize(*a) - (i++) > 0)
			rev_a(a);
	}
	return ;
}

// Prends l'element choisi pour le placer en tete de la liste B

void	be_first_b(t_list **b, t_list *tmp)
{
	t_list	*temp;
	int		i;

	temp = *b;
	i = 0;
	while (compare_str(temp->content, tmp->content) != 0)
	{
		temp = temp->next;
		if (temp == NULL)
			return ;
		i ++;
	}
	if (i == 1)
		swap_b(b);
	else if (i < ft_lstsize(*b) / 2)
	{
		while (i--)
			rotate_b(b);
	}
	else
	{
		while (ft_lstsize(*b) - (i++) > 0)
			rev_b(b);
	}
	return ;
}
// Envoie les elements dans l'ordre decroissant vers A

void	split_b(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = NULL;
	while (*b)
	{
		tmp = find_max(b);
		be_first_b(b, tmp);
		push_a(b, a);
	}
}

// Envoie les element plus petit que le pivot de A vers B

void	split(t_list **a, t_list **b)
{
	t_list	*pivot;
	t_list	*tmp;

	pivot = find_pivot(a, ft_lstsize(*a));
	tmp = *a;
	while (tmp)
	{
		if (compare_str(pivot->content, tmp->content) == 1)
		{
			be_first(a, tmp);
			if (checkend(a, b))
				return ;
			push_b(a, b);
			if (checkend(a, b))
				return ;
			tmp = *a;
		}
		else
			tmp = tmp->next;
	}
}

// Lance le trie tant que ce n'est pas fini

void	sort(t_list **a, t_list **b)
{
	if (!a)
		return ;
	if (check(a) == 0 && !(*b))
		return ;
	if (ft_lstsize(*a) <= 3)
	{
		little(a);
		split_b(a, b);
		return ;
	}
	split(a, b);
	sort(a, b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annexe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <agomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 10:53:28 by agomes-g          #+#    #+#             */
/*   Updated: 2023/06/15 11:52:01 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freelist(t_list *list)
{
	t_list	*tmp;
	t_list	*next;

	tmp = list;
	while (tmp != NULL)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}

// Verifie si la liste est deja triee

int	check(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp->next)
	{
		if (compare_str(tmp->content, tmp->next->content) == 1)
			return (1);
		tmp = tmp->next;
		if (!tmp)
			break ;
	}
	return (0);
}

// Touve l'element le plus eleve de la liste

t_list	*find_max(t_list **a)
{
	t_list	*tmp;
	t_list	*max;

	tmp = *a;
	max = *a;
	while (tmp)
	{
		if (compare_str(max->content, tmp->content) == -1)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

void	little_2(t_list **a)
{
	if (compare_str((*a)->content, (*a)->next->content) == 1)
	{
		if (compare_str((*a)->content, (*a)->next->next->content) == 1)
		{	
			rotate_a(a);
			if (compare_str((*a)->content, (*a)->next->content) == 1)
				swap_a(a);
		}
		else
			swap_a(a);
		return ;
	}
	if (compare_str((*a)->content, (*a)->next->next->content) == 1)
	{
		rev_a(a);
		return ;
	}
	else
	{
		rev_a(a);
		swap_a(a);
		return ;
	}
}

// Trie une liste de 3 elements au plus

void	little(t_list **a)
{
	t_list	*tmp;
	int		len;

	if (!(*a))
		return ;
	tmp = (*a)->next;
	len = ft_lstsize(*a);
	if (len == 1)
		return ;
	if (len == 2)
	{
		if (compare_str((*a)->content, tmp->content) == 1)
			swap_a(a);
		return ;
	}
	else
		return (little_2(a));
}

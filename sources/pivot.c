/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <agomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:59:38 by agomes-g          #+#    #+#             */
/*   Updated: 2023/09/19 07:32:58 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Permet d'incrementer inf et sup

void	loop_pivot(t_list **a, t_list *piv, int *inf, int *sup)
{
	t_list	*temp;
	int		i;
	int		j;

	temp = *a;
	i = 0;
	j = 0;
	while (temp)
	{
		if (compare_str(piv->content, temp->content) == -1)
		{
			i ++;
			*sup = i;
		}
		if (compare_str(piv->content, temp->content) == 1)
		{
			j ++;
			*inf = j;
		}
		temp = temp->next;
	}
}

// suite de la fonction qui suit

t_list	*find_med_annexe(t_list **a, t_list *a_bis, int inf)
{
	if (inf > 40)
		return (find_med_pivot(a, a_bis, inf));
	return (a_bis);
}

// Trouve une nvlle mediane a partir de la precedente

t_list	*find_med_pivot(t_list **a, t_list *piv, int len_bis)
{
	t_list	*a_bis;
	int		inf_bis;
	int		sup_bis;

	a_bis = *a;
	while (a_bis)
	{
		inf_bis = 0;
		sup_bis = 0;
		if (compare_str(piv->content, a_bis->content) == 1)
		{
			loop_pivot(a, a_bis, &inf_bis, &sup_bis);
			if (sup_bis == len_bis / 2 || inf_bis == len_bis / 2)
			{
				if (inf_bis > 40)
					return (find_med_annexe(a, a_bis, inf_bis));
				return (a_bis);
			}
		}
		if (a_bis->next == NULL)
			return (a_bis);
		a_bis = a_bis->next;
	}
	return (piv);
}

// Trouve la mediane qui devient pivot 

t_list	*find_pivot(t_list **a, int len)
{
	t_list	*piv;
	int		sup;
	int		inf;

	piv = *a;
	while (piv)
	{
		sup = 0;
		inf = 0;
		loop_pivot(a, piv, &inf, &sup);
		if (sup == len / 2 || inf == len / 2)
		{
			if (inf > 40)
				return (find_med_pivot(a, piv, inf));
			return (piv);
		}
		else
		{
			if (piv->next == NULL)
				return (piv);
			piv = piv->next;
		}
	}
	return (piv);
}

int	checkend(t_list **a, t_list **b)
{
	if (check(a) == 0)
	{
		if (!(*b))
			return (1);
		if (compare_str((*a)->content, (*b)->content) == 1)
			return (split_b(a, b), 1);
	}
	return (0);
}

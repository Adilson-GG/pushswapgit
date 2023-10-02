/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <agomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:46:35 by agomes-g          #+#    #+#             */
/*   Updated: 2023/09/29 07:23:54 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Compare deux chaines de caracteres (nombres) entre elles

int	compare_str_3(char *str1, char *str2, int i, int j)
{
	int	s1;
	int	s2;
	int	a;
	int	b;

	s1 = 1;
	s2 = 1;
	a = 0;
	b = 0;
	if (i)
		s1 = -1;
	if (j)
		s2 = -1;
	while (str1[a] != '\0' && str2[b] != '\0')
	{
		if (str1[a] > str2[b])
			return (1 * s1);
		else if (str1[a] < str2[b])
			return (-1 * s2);
		a ++;
		b ++;
	}
	if (s1 == s2)
		return (0);
	return (s1);
}

int	compare_str_2(char *str1, char *str2, int i, int j)
{
	int	sign_1;
	int	sign_2;

	sign_1 = 0;
	sign_2 = 0;
	if (str1[i] == '+')
		sign_1 ++;
	if (str2[j] == '+')
		sign_2 ++;
	if (ft_strlen(&str1[i + sign_1]) > ft_strlen(&str2[j + sign_2]))
	{
		if (i)
			return (-1);
		return (1);
	}
	else if (ft_strlen(&str1[i + sign_1]) < ft_strlen(&str2[j + sign_2]))
	{
		if (j)
			return (1);
		return (-1);
	}
	return (compare_str_3(&str1[i + sign_1], &str2[j + sign_2], i, j));
}

int	compare_str(char *str1, char *str2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str1[0] == '-')
		i ++;
	if (str2[0] == '-')
		j ++;
	return (compare_str_2(str1, str2, i, j));
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i ++;
	}
	free(tab);
}

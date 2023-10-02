/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <agomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 08:29:09 by agomes-g          #+#    #+#             */
/*   Updated: 2023/09/30 14:59:31 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_only_digits(char **av, int ac)
{
	int	i;
	int	nb;

	nb = 0;
	while (nb++ < ac - 1)
	{
		i = 0;
		while (av[nb][i])
		{
			if (av[nb][i] == '-' || av[nb][i] == '+')
			{
				if (av[nb][i + 1] == ' ')
					return (0);
				if (i > 0 && av[nb][i - 1] != ' ')
					return (0);
				i ++;
			}
			if (!ft_isdigit(av[nb][i]) && av[nb][i] != ' ')
				return (0);
			i ++;
		}
	}
	return (1);
}

int	ft_unicity_string(char *s)
{
	char	**tab;
	int		i;
	int		j;

	tab = ft_split(s, ' ');
	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_atoi_long(tab[i]) == ft_atoi_long(tab[j]))
			{
				free_tab(tab);
				return (0);
			}
			j ++;
		}
		i ++;
	}
	free_tab(tab);
	return (1);
}

int	ft_unicity(char **av, int ac)
{
	int	i;
	int	j;

	i = 1;
	if (ac == 2)
		return (ft_unicity_string(av[1]));
	while (i < ac)
	{
		if (av[i][0] == '\0')
			return (0);
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi_long(av[i]) == ft_atoi_long(av[j]))
				return (0);
			j ++;
		}
		i ++;
	}
	return (1);
}

long	ft_atoi_long(const char *nptr)
{
	int		i;
	long	s;
	long	conv;

	i = 0;
	conv = 0;
	s = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i ++;
	if (nptr[i] != '-' && !(nptr[i] >= 48 && nptr[i] <= 57) && nptr[i] != '+')
		return (0);
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s = -1;
		i ++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		conv = (conv * 10) + (nptr[i] - '0');
		i ++;
	}
	return (s * conv);
}

int	ft_overflow(char **av, int ac)
{
	int	nb;

	nb = 1;
	while (nb < ac)
	{
		if (ft_atoi_long(av[nb]) != ft_atoi(av[nb]))
			return (0);
		nb ++;
	}
	return (1);
}

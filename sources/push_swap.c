/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <agomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:37:03 by agomes-g          #+#    #+#             */
/*   Updated: 2023/09/27 11:26:42 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_errors(char **av, int ac)
{
	if (ac < 2)
		return (0);
	if (av[1][0] == '\0')
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (ft_unicity(av, ac) == 0 || ft_only_digits(av, ac) == 0
		|| ft_overflow(av, ac) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}

void	many_args(t_list *a, t_list *b, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_lstadd_back(&a, ft_lstnew(argv[i]));
		i ++;
	}
	sort(&a, &b);
	freelist(a);
}

void	freetab(char **tab)
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

int	one_arg(t_list *a, t_list *b, char **argv)
{
	int		i;
	char	**tab;

	if (!ft_errors(argv, 2))
		return (0);
	i = 0;
	tab = ft_split(argv[1], ' ');
	if (!tab)
		return (0);
	while (tab[i])
	{
		ft_lstadd_back(&a, ft_lstnew(tab[i]));
		i ++;
	}
	sort(&a, &b);
	freetab(tab);
	freelist(a);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (!ft_errors(argv, argc))
		return (0);
	a = NULL;
	b = NULL;
	if (argc == 2)
	{
		if (!one_arg(a, b, argv))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
	}
	if (argc > 2)
		many_args(a, b, argc, argv);
	return (0);
}

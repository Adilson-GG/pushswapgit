/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <agomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:36:51 by agomes-g          #+#    #+#             */
/*   Updated: 2023/09/19 12:10:45 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

void	swap_a(t_list **a);
void	swap_b(t_list **a);
void	ss(t_list **a, t_list **b);

void	push_a(t_list **from, t_list **to);
void	push_b(t_list **from, t_list **to);

void	rotate_a(t_list **a);
void	rotate_b(t_list **a);
void	rr(t_list **a, t_list **b);

void	rev_a(t_list **a);
void	rev_b(t_list **a);
void	rrr(t_list **a, t_list **b);

int		ft_only_digits(char **av, int ac);
int		ft_errors(char **av, int ac);
int		ft_unicity(char **av, int ac);
long	ft_atoi_long(const char *nptr);
int		ft_overflow(char **av, int ac);

t_list	*find_pivot(t_list **a, int len);
t_list	*find_med_pivot(t_list **a, t_list *piv, int len_bis);

void	split(t_list **a, t_list **b);
void	split_b(t_list **a, t_list **b);
void	sort(t_list **list, t_list **b);
void	sort_2(t_list **a, t_list **b);
void	merge(t_list **list, t_list **greater);
void	little(t_list **a);
int		check(t_list **list);
int		checkend(t_list **a, t_list **b);
void	lstprint(t_list *a);
void	little(t_list **a);
t_list	*find_max(t_list **a);
int		compare_str(char *str1, char *str2);
void	freelist(t_list *list);
void	free_tab(char **tab);

#endif

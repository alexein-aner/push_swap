/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamil <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:05:40 by kamil             #+#    #+#             */
/*   Updated: 2024/10/31 10:52:06 by kamil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_cheapest(t_stack *from, t_stack *to);
int		get_depth(t_stack *from, int n);
int		get_target(t_stack *to_search, int n, int u_or_l);
int		is_biggest(t_stack *to_search, int n);
int		is_smallest(t_stack *to_search, int n);
int		get_biggest(t_stack *to_search);
int		get_immediate_lower(t_stack *to_search, int n);
int		push_cheapest(t_stack *from, t_stack *to, int n);
void	sort_three(t_stack *a);
void	bring_to_top(t_stack *a, int target);
void	push_back(t_stack *from, t_stack *to);
int		get_immediate_upper(t_stack *to_search, int n);
void	bring_min_to_top(t_stack *stack);

void	sort(t_stack *a, t_stack *b)
{
	int	ntm;

	ntm = -1;
	if (a->size >= 4)
		pb(a, b);
	if (a->size >= 5)
		pb(a, b);
	while (a->size > 3)
	{
		ntm = check_cheapest(a, b);
		push_cheapest(a, b, ntm);
	}
	sort_three(a);
	if (b->size != 0)
	{
		push_back(b, a);
		bring_min_to_top(a);
	}
	return ;
}

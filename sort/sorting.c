/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamil <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:05:40 by kamil             #+#    #+#             */
/*   Updated: 2024/10/31 11:49:05 by kamil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

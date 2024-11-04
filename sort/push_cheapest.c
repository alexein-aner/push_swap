/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamil <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:59:55 by kamil             #+#    #+#             */
/*   Updated: 2024/11/04 12:05:02 by kamil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_from_to(t_stack *from, int *depth)
{
	if (*depth > 0)
	{
		ra(from);
		(*depth)--;
	}
	else if (*depth < 0)
	{
		rra(from);
		(*depth)++;
	}
}

static void	rotate_target_to(t_stack *to, int *depth)
{
	if (*depth > 0)
	{
		rb(to);
		(*depth)--;
	}
	else if (*depth < 0)
	{
		rrb(to);
		(*depth)++;
	}
}

int	push_cheapest(t_stack *from, t_stack *to, int n)
{
	int	n_depth;
	int	target;
	int	target_depth;

	n_depth = get_depth(from, n);
	target = get_target(to, n, 1);
	target_depth = get_depth(to, target);
	while (n_depth != 0 || target_depth != 0)
	{
		if (n_depth > 0 && target_depth > 0)
		{
			rr(from, to);
			n_depth--;
			target_depth--;
		}
		else if (n_depth < 0 && target_depth < 0)
		{
			rrr(from, to);
			n_depth++;
			target_depth++;
		}
		else
		{
			rotate_from_to(from, &n_depth);
			rotate_target_to(to, &target_depth);
		}
	}
	pb(from, to);
	return (0);
}

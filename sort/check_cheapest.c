/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cheapest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamil <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:08:23 by kamil             #+#    #+#             */
/*   Updated: 2024/11/04 12:27:45 by kamil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_combined_moves(int f_depth, int target_depth)
{
	if ((f_depth > 0 && target_depth > 0) || (f_depth < 0 && target_depth < 0))
		return (max(abs(f_depth), abs(target_depth)));
	return (abs(f_depth) + abs(target_depth));
}

int	check_cheapest(t_stack *from, t_stack *to)
{
	t_node	*curr;
	int		curr_steps;
	int		cheapest_val;
	int		f_depth;
	int		target;
	int		target_depth;
	int		combined_moves;

	curr = from->top;
	curr_steps = INT_MAX;
	cheapest_val = INT_MIN;
	while (curr)
	{
		f_depth = get_depth(from, curr->val);
		target = get_target(to, curr->val, 1);
		target_depth = get_depth(to, target);
		combined_moves = calculate_combined_moves(f_depth, target_depth);
		if (combined_moves < curr_steps)
		{
			curr_steps = combined_moves;
			cheapest_val = curr->val;
		}
		curr = curr->next;
	}
	return (cheapest_val);
}

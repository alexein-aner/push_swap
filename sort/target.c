/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamil <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:52:09 by kamil             #+#    #+#             */
/*   Updated: 2024/11/04 12:26:50 by kamil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_target(t_stack *to_search, int n, int u_or_l)
{
	if (is_biggest(to_search, n) || is_smallest(to_search, n))
		return (get_biggest(to_search));
	else if (u_or_l)
		return (get_immediate_lower(to_search, n));
	else if (!u_or_l)
		return (get_immediate_upper(to_search, n));
	else
		return (INT_MIN);
}

int	get_immediate_lower(t_stack *to_search, int n)
{
	int		dif;
	int		target;
	t_node	*curr;

	if (!to_search->top)
		return (INT_MIN);
	dif = INT_MAX;
	target = INT_MIN;
	curr = to_search->top;
	while (curr)
	{
		if (n - curr->val < dif && n - curr->val > 0)
		{
			dif = n - curr->val;
			target = curr->val;
		}
		curr = curr->next;
	}
	return (target);
}

int	get_immediate_upper(t_stack *stack, int target)
{
	t_node	*current;
	int		closest_val;
	int		closest_diff;
	int		diff;

	if (!stack || !stack->top)
		return (INT_MIN);
	current = stack->top;
	closest_val = INT_MIN;
	closest_diff = INT_MAX;
	if (is_biggest(stack, target))
		return (INT_MAX);
	while (current)
	{
		diff = current->val - target;
		if (diff > 0 && diff < closest_diff)
		{
			closest_diff = diff;
			closest_val = current->val;
		}
		current = current->next;
	}
	return (closest_val);
}

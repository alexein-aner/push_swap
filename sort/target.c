/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamil <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:52:09 by kamil             #+#    #+#             */
/*   Updated: 2024/10/31 14:53:05 by kamil            ###   ########.fr       */
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
		return (-1);
}

int	is_biggest(t_stack *to_search, int n)
{
	t_node	*curr;

	if (!to_search->top)
		return (-1);
	curr = to_search->top;
	while (curr)
	{
		if (n < curr->val)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	is_smallest(t_stack *to_search, int n)
{
	t_node	*curr;

	if (!to_search->top)
		return (-1);
	curr = to_search->top;
	while (curr)
	{
		if (n > curr->val)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	get_biggest(t_stack *to_search)
{
	t_node	*curr;
	int		max;

	if (!to_search->top)
		return (-1);
	curr = to_search->top;
	max = curr->val;
	while (curr)
	{
		if (max < curr->val)
			max = curr->val;
		curr = curr->next;
	}
	return (max);
}

int	get_immediate_lower(t_stack *to_search, int n)
{
	int		dif;
	int		target;
	t_node	*curr;

	if (!to_search->top)
		return (-1);
	dif = INT_MAX;
	target = -1;
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
		return (-1);
	current = stack->top;
	closest_val = -1;
	closest_diff = INT_MAX;
	if (is_biggest(stack, target))
		return (-2);
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

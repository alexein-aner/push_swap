/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamil <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:50:13 by kamil             #+#    #+#             */
/*   Updated: 2024/11/05 12:27:54 by kamil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_depth(t_stack *from, int n)
{
	int		i;
	t_node	*curr;

	i = 0;
	curr = from->top;
	while (curr)
	{
		if (curr->val == n)
		{
			if (i <= from->size / 2)
				return (i);
			else
				return (i - from->size);
		}
		i++;
		curr = curr->next;
	}
	return (INT_MIN);
}

void	bring_to_top(t_stack *a, int target)
{
	int	depth;

	depth = get_depth(a, target);
	while (depth != 0)
	{
		if (depth < 0)
		{
			rra(a);
			depth++;
		}
		if (depth > 0)
		{
			ra(a);
			depth--;
		}
	}
}

void	bring_min_to_top(t_stack *stack)
{
	int		min_val;

	if (!stack || !stack->top)
		return ;
	min_val = get_smallest(stack);
	bring_to_top(stack, min_val);
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
		return (1);
	current = stack->top;
	while (current && current->next)
	{
		if (current->val > current->next->val)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort_two(t_stack *stack)
{
	if (!stack || !stack->top || !stack->top->next)
		return ;
	if (stack->top->val > stack->top->next->val)
		sa(stack);
}

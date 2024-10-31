/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamil <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:50:13 by kamil             #+#    #+#             */
/*   Updated: 2024/10/31 14:53:53 by kamil            ###   ########.fr       */
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
	return (-1);
}

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->val;
	second = a->top->next->val;
	third = a->top->next->next->val;
	if (first < second && second < third)
		return ;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && first > third && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && first > third && second < third)
		ra(a);
	else if (first < second && first > third)
		rra(a);
	else if (first < second && second > third)
	{
		sa(a);
		ra(a);
	}
}

void	push_back(t_stack *b, t_stack *a)
{
	t_node	*curr;
	int		target;

	curr = b->top;
	while (curr)
	{
		if (b->top == NULL)
			break ;
		curr = b->top;
		target = get_immediate_upper(a, curr->val);
		if (target == -2)
		{
			pa(a, b);
			curr = curr->next;
			continue ;
		}
		bring_to_top(a, target);
		pa(a, b);
		curr = curr->next;
	}
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
	t_node	*current;
	int		min_val;
	int		min_depth;
	int		depth;
	int		half_size;

	if (!stack || !stack->top)
		return ;
	current = stack->top;
	min_val = current->val;
	min_depth = 0;
	depth = 0;
	while (current)
	{
		if (current->val < min_val)
		{
			min_val = current->val;
			min_depth = depth;
		}
		current = current->next;
		depth++;
	}
	half_size = stack->size / 2;
	while (min_depth != 0)
	{
		if (depth >= half_size)
		{
			ra(stack);
			min_depth--;
		}
		else
		{
			rra(stack);
			min_depth--;
		}
	}
}

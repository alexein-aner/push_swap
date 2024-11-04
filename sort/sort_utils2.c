/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamil <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:29:42 by kamil             #+#    #+#             */
/*   Updated: 2024/11/04 13:22:22 by kamil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (target == INT_MAX)
			target = get_smallest(a);
		bring_to_top(a, target);
		pa(a, b);
		curr = curr->next;
	}
}

int	get_smallest(t_stack *to_search)
{
	t_node	*curr;
	int		min;

	if (!to_search->top)
		return (INT_MAX);
	curr = to_search->top;
	min = curr->val;
	while (curr)
	{
		if (min > curr->val)
			min = curr->val;
		curr = curr->next;
	}
	return (min);
}

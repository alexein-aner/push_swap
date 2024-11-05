/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamil <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:29:42 by kamil             #+#    #+#             */
/*   Updated: 2024/11/05 12:19:32 by kamil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_largest_at_top(t_stack *a)
{
	if (a->top->next->val < a->top->next->next->val)
		ra(a);
	else
	{
		sa(a);
		rra(a);
	}
}

static void	handle_smallest_in_middle(t_stack *a)
{
	sa(a);
	ra(a);
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
	else if (first > second && first > third)
		handle_largest_at_top(a);
	else if (first < second && first > third)
		rra(a);
	else if (first < second && second > third)
		handle_smallest_in_middle(a);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamil <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:05:40 by kamil             #+#    #+#             */
/*   Updated: 2024/10/31 10:46:10 by kamil            ###   ########.fr       */
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
		else if (n_depth > 0)
		{
			ra(from);
			n_depth--;
		}
		else if (n_depth < 0)
		{
			rra(from);
			n_depth++;
		}
		else if (target_depth > 0)
		{
			rb(to);
			target_depth--;
		}
		else if (target_depth < 0)
		{
			rrb(to);
			target_depth++;
		}
	}
	pb(from, to);
	return (0);
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
	cheapest_val = -1;
	while (curr)
	{
		f_depth = get_depth(from, curr->val);
		target = get_target(to, curr->val, 1);
		target_depth = get_depth(to, target);
		if ((f_depth > 0 && target_depth > 0) || (f_depth < 0
				&& target_depth < 0))
			combined_moves = max(abs(f_depth), abs(target_depth));
		else
			combined_moves = abs(f_depth) + abs(target_depth);
		if (combined_moves < curr_steps)
		{
			curr_steps = combined_moves;
			cheapest_val = curr->val;
		}
		curr = curr->next;
	}
	return (cheapest_val);
}

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

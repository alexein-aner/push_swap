/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamil <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:15:29 by kamil             #+#    #+#             */
/*   Updated: 2024/11/04 13:27:23 by kamil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack *a, t_stack *b)
{
	t_node	*node;
	t_node	*node2;

	if (!a->top || a->top == a->bottom)
		return ;
	node = a->top;
	a->top = node->next;
	a->top->prev = NULL;
	a->bottom->next = node;
	node->prev = a->bottom;
	node->next = NULL;
	a->bottom = node;
	if (!b->top || b->top == b->bottom)
		return ;
	node2 = b->top;
	b->top = node2->next;
	b->top->prev = NULL;
	b->bottom->next = node2;
	node2->prev = b->bottom;
	node2->next = NULL;
	b->bottom = node2;
	write(1, "rr\n", 3);
}

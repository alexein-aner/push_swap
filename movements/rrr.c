/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamil <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:48:49 by kamil             #+#    #+#             */
/*   Updated: 2024/11/04 13:27:30 by kamil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack *a, t_stack *b)
{
	t_node	*node;
	t_node	*node2;

	if (!a->top || a->top == a->bottom)
		return ;
	node = a->bottom;
	a->bottom = node->prev;
	a->bottom->next = NULL;
	node->prev = NULL;
	node->next = a->top;
	a->top->prev = node;
	a->top = node;
	if (!b->top || b->top == b->bottom)
		return ;
	node2 = b->bottom;
	b->bottom = node2->prev;
	b->bottom->next = NULL;
	node2->prev = NULL;
	node2->next = b->top;
	b->top->prev = node2;
	b->top = node2;
	write(1, "rrr\n", 4);
}

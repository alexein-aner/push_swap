/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamil <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:47:02 by kamil             #+#    #+#             */
/*   Updated: 2024/11/04 13:27:15 by kamil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_stack *b)
{
	t_node	*node;

	if (!b->top || b->top == b->bottom)
		return ;
	node = b->bottom;
	b->bottom = node->prev;
	b->bottom->next = NULL;
	node->prev = NULL;
	node->next = b->top;
	b->top->prev = node;
	b->top = node;
	write(1, "rrb\n", 4);
}

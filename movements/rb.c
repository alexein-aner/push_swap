/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamil <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:14:15 by kamil             #+#    #+#             */
/*   Updated: 2024/11/04 13:26:57 by kamil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stack *b)
{
	t_node	*node;

	if (!b->top || b->top == b->bottom)
		return ;
	node = b->top;
	b->top = node->next;
	b->top->prev = NULL;
	b->bottom->next = node;
	node->prev = b->bottom;
	node->next = NULL;
	b->bottom = node;
	write(1, "rb\n", 3);
}

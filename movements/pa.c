/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamil <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:11:18 by kamil             #+#    #+#             */
/*   Updated: 2024/10/31 14:58:15 by kamil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (b->top == NULL)
		return ;
	node = b->top;
	b->top = node->next;
	if (b->top != NULL)
		b->top->prev = NULL;
	else
		b->bottom = NULL;
	node->next = a->top;
	if (a->top != NULL)
		a->top->prev = node;
	else
		a->bottom = node;
	a->top = node;
	node->prev = NULL;
	a->size++;
	b->size--;
	printf("pa\n");
}

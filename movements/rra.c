/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamil <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:47:51 by kamil             #+#    #+#             */
/*   Updated: 2024/10/31 14:58:49 by kamil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	t_node	*node;

	if (!a->top || a->top == a->bottom)
		return ;
	node = a->bottom;
	a->bottom = node->prev;
	a->bottom->next = NULL;
	node->prev = NULL;
	node->next = a->top;
	a->top->prev = node;
	a->top = node;
	printf("rra\n");
}

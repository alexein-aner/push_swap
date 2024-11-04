/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamil <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:25:33 by kamil             #+#    #+#             */
/*   Updated: 2024/11/04 13:28:08 by kamil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = init_stack();
	if (!stack_a)
		error();
	stack_b = init_stack();
	if (!stack_b)
		error();
	if (!validate_input(argc, argv))
		error();
	parse_and_init_stack(argc, argv, stack_a);
	if (has_duplicates(stack_a))
		error();
	if (!is_sorted(stack_a))
		sort(stack_a, stack_b);
		/*
	if (is_sorted(stack_a))
		printf("sorted\n");
	else
		printf("failed to sort\n");
	print_stacks(stack_a, stack_b);
	*/
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

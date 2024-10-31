/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamil <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:25:33 by kamil             #+#    #+#             */
/*   Updated: 2024/10/31 16:05:00 by kamil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = init_stack();
	if (!stack_a)
	{
		printf("Failed to initialize stack_a\n");
		return (1);
	}
	stack_b = init_stack();
	if (!stack_b)
	{
		printf("Failed to initialize stack_b\n");
		return (1);
	}
	if (!validate_input(argc, argv))
		return (1);
	parse_and_init_stack(argc, argv, stack_a);
	if (has_duplicates(stack_a))
	{
		printf("ERROR: the given numbers cannot have any duplications\n");
		return (1);
	}
	sort(stack_a, stack_b);
//	print_stacks(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

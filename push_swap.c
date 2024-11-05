/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamil <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:25:33 by kamil             #+#    #+#             */
/*   Updated: 2024/11/05 11:55:48 by kamil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_errors(int argc, char **argv);

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (check_errors(argc, argv))
		error();
	stack_a = init_stack();
	stack_b = init_stack();
	if (!stack_b || !stack_b)
		error();
	parse_and_init_stack(argc, argv, stack_a);
	if (has_duplicates(stack_a))
		error();
	if (!is_sorted(stack_a))
		sort(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

static int	check_errors(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc > 1 && is_empty_string(argv[1]))
		return (1);
	if (argc == 1)
		return (1);
	while (i < argc)
	{
		if (!is_within_int_range(argv[i]))
			return (1);
		i++;
	}
	if (!validate_input(argc, argv))
		return (1);
	return (0);
}

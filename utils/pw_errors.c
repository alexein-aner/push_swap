/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamil <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:40:49 by kamil             #+#    #+#             */
/*   Updated: 2024/10/29 10:37:20 by kamil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_a;
	t_node	*current_b;

	current_a = stack_a ? stack_a->top : NULL;
	current_b = stack_b ? stack_b->top : NULL;
	printf("Stack A (top to bottom)\tStack B (top to bottom)\n");
	printf("-------------------------------------------------\n");
	while (current_a || current_b)
	{
		if (current_a)
		{
			printf("%-20d", current_a->val);
			current_a = current_a->next;
		}
		else
		{
			printf("%-20s", " ");
		}
		if (current_b)
		{
			printf("%d", current_b->val);
			current_b = current_b->next;
		}
		printf("\n");
	}
}

int	has_duplicates(t_stack *stack)
{
	t_node	*current;
	t_node	*inner;

	current = stack->top;
	while (current != NULL)
	{
		inner = current->next;
		while (inner != NULL)
		{
			if (current->val == inner->val)
				return (1);
			inner = inner->next;
		}
		current = current->next;
	}
	return (0);
}

int	is_valid_input(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	validate_input(int argc, char **argv)
{
	char	**numbers;
	int		i;

	if (argc == 1)
	{
		printf("ERROR: You need to input the numbers to be sorted\n");
		return (0);
	}
	i = 0;
	if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		if (!numbers)
			return (0);
		while (numbers[i])
		{
			if (!is_valid_input(numbers[i]))
			{
				printf("Invalid input: %s\n", numbers[i]);
				ft_free_split(numbers);
				return (0);
			}
			i++;
		}
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			if (!is_valid_input(argv[i]))
			{
				printf("Invalid input: %s\n", argv[i]);
				return (0);
			}
			i++;
		}
	}
	return (1);
}

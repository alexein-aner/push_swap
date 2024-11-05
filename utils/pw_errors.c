/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamil <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:40:49 by kamil             #+#    #+#             */
/*   Updated: 2024/11/05 12:02:22 by kamil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

int	is_empty_string(const char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (1);
	while (str[i])
	{
		if (!ft_isspace((unsigned char)str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_within_int_range(char *str)
{
	if (*str == '-')
	{
		if (ft_strlen(str) > 11 || (ft_strlen(str) == 11 && ft_strncmp(str,
					"-2147483648", ft_strlen(str)) > 0))
			return (0);
	}
	else
	{
		if (ft_strlen(str) > 10 || (ft_strlen(str) == 10 && ft_strncmp(str,
					"2147483647", ft_strlen(str)) > 0))
			return (0);
	}
	return (1);
}
/*
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
*/

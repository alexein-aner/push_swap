/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamil <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:33:55 by kamil             #+#    #+#             */
/*   Updated: 2024/10/29 10:38:06 by kamil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

typedef struct s_node
{
	int				val;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	t_node			*bottom;
	int				size;
}					t_stack;

unsigned int		ft_strlcpy(char *dest, char *src, unsigned int size);
int					ft_strlen(char *str);
int					ft_strncmp(char *s1, char *s2, size_t n);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(char *s1);
char				*ft_substr(char *s, unsigned int st, size_t len);
char				*ft_strjoin(char *s1, char *s2);
char				**ft_split(char *s, char c);
void				ft_free_split(char **split);
int					ft_atoi(char *str);
int					ft_isdigit(int c);
void				parse_and_init_stack(int argc, char **argv, t_stack *stack);
void				push_stack(t_stack *stack, int value);
t_stack				*init_stack(void);
t_node				*new_node(int value);
void				free_stack(t_stack *stack);
//void				print_stack(t_stack *stack);
int					has_duplicates(t_stack *stack);
int					is_valid_input(char *str);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
void				ra(t_stack *a);
void				rb(t_stack *b);
int					validate_input(int argc, char **argv);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);
void				sa(t_stack *a);
int					check_cheapest(t_stack *from, t_stack *to);
void				print_stacks(t_stack *stack_a, t_stack *stack_b);

void				sort(t_stack *a, t_stack *b);

#endif

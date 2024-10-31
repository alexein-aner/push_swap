/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knieve-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:50:08 by knieve-l          #+#    #+#             */
/*   Updated: 2024/10/23 16:02:36 by kamil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(char *src)
{
	char	*copy;
	size_t	length;
	size_t	i;

	if (!src)
		return (NULL);
	length = ft_strlen(src);
	copy = malloc(length + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < length)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

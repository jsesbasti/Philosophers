/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-25 17:26:38 by jsebasti          #+#    #+#             */
/*   Updated: 2025-04-25 17:26:38 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;
	size_t	total_size;

	i = -1;
	total_size = count * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	while (++i < total_size)
		((char *)ptr)[i] = 0;
	return (ptr);
}
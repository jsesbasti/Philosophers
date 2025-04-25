/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-25 17:35:31 by jsebasti          #+#    #+#             */
/*   Updated: 2025-04-25 17:35:31 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	ft_strdigit(char **av)
{
	size_t	i;
	size_t	j;

	j = 1;
	while (av[j])
	{
		i = 0;
		while (av[j][i])
		{
			if (ft_isdigit(av[j][i]) == false)
				return (false);
			i++;
		}
		j++;
	}
	return (true);
}
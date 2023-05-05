/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:49:53 by jsebasti          #+#    #+#             */
/*   Updated: 2023/05/04 19:21:26 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_strdigit(char **av, int i, int j)
{
	while (av[j])
	{
		while (av[j][i])
		{
			if (av[j][i] < '0' || av[j][i] > '9' || ft_strlen(av[j]) > 10)
				return (1);
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	 check_args(int ac, char **av, t_init *p)
{
	if ((ac == 5 || ac == 6) && !ft_strdigit(av, 0, 1))
	{
		p->arg.total = ft_atoi(av[1]);
		p->arg.die = ft_atoi(av[2]);
		p->arg.eat = ft_atoi(av[3]);
		p->arg.sleep = ft_atoi(av[4]);
		if (ac == 6)
			p->arg.m_eat = ft_atoi(av[5]);
		if (p->arg.total <= 0 || p->arg.die <= 0 || \
			p->arg.eat <= 0 || p->arg.sleep <= 0)
			return (1);
		return (0);
	}
	return (1);
}
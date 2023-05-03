/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:53:34 by jsebasti          #+#    #+#             */
/*   Updated: 2023/05/03 00:13:06 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutex(t_init *ini)
{
	pthread_mutex_init(&ini->arg.write_mutex, NULL);
	pthread_mutex_init(&ini->arg.dead, NULL);
	pthread_mutex_init(&ini->arg.time_eat, NULL);
	pthread_mutex_init(&ini->arg.finish, NULL);
}

int	initialize(t_init *ini)
{
	int	i;

	i = 0;
	ini->arg.start_t = actual_time();
	if (ini->arg.start_t == 1)
		return (1);
	ini->arg.stop = 0;
	ini->arg.nb_p_finish = 0;
	init_mutex(ini);
	while (i < ini->arg.n_philos)
	{
		ini->philo[i].id = i + 1;
		ini->philo[i].ms_eat = ini->arg.start_t;
		ini->philo[i].nb_eat = 0;
		ini->philo[i].finish = 0;
		ini->philo[i].r_fork = NULL;
		pthread_mutex_init(&ini->philo[i].l_fork, NULL);
		if (ini->arg.n_philos == 1)
			return (0);
		if (i == ini->arg.n_philos - 1)
			ini->philo[i].r_fork = &ini->philo[0].l_fork;
		else
			ini->philo[i].r_fork = &ini->philo[i + 1].l_fork;
		i++;
	}
	return (0);
}

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

int	 check_args(int ac, char **av, t_init *ini)
{
	if ((ac == 5 || ac == 6) && !ft_strdigit(av, 0, 1))
	{
		ini->arg.n_philos = ft_atoi(av[1]);
		ini->arg.time_d = ft_atoi(av[2]);
		ini->arg.time_e = ft_atoi(av[3]);
		ini->arg.time_s = ft_atoi(av[4]);
		if (ac == 6)
			ini->arg.m_eat = ft_atoi(av[5]);
		if (ini->arg.n_philos <= 0 || ini->arg.time_d <= 0 || \
			ini->arg.time_e <= 0 || ini->arg.time_s <= 0)
			return (1);
		return (0);
	}
	return (1);
}
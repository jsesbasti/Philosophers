/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-25 17:41:18 by jsebasti          #+#    #+#             */
/*   Updated: 2025-04-25 17:41:18 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_forks(t_philo *philo, t_philo *philos, unsigned int num_philos)
{
	size_t	philo_pos;
	
	philo_pos = philo->id - 1;
	pthread_mutex_init(&philo->l_fork, NULL);
	if (philo_pos == num_philos - 1)
		philo->l_fork = &philos[0].r_fork;
	else
		philo->l_fork = &philos[philo->id].r_fork;
}

int	initialize(t_init *ini)
{
	size_t	i;
	t_args	*vars;
	t_philo	*philos;

	i = -1;
	vars = &ini->init_vars;
	philos = ini->philos;
	vars->start_time = actual_time();
	if (vars->start_time == 1)
		return (ERROR);
	while (++i < vars->num_philos)
	{
		philos[i].id = i + 1;
		philos[i].nb_eat = 0;
		philos[i].finished = false;
		philos[i].l_fork = NULL;
		init_forks(&philos[i], philos, vars->num_philos);
	}
	return (SUCCESS);
}
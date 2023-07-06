/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 00:02:47 by jsebasti          #+#    #+#             */
/*   Updated: 2023/07/06 19:14:19 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo *ph)
{
	if (!check_dead(ph, 0) && !ph->finish && ((actual_time() - ph->ms_eat) \
		>= (long)(ph->p_arg->time_d)))
	{
		pthread_mutex_unlock(&ph->p_arg->time_eat);
		pthread_mutex_unlock(&ph->p_arg->finish);
		write_status("died.\n", ph);
		check_dead(ph, 1);
		return (1);
	}
	pthread_mutex_unlock(&ph->p_arg->time_eat);
	pthread_mutex_unlock(&ph->p_arg->finish);
	return (0);
}

void	sleep_think(t_philo *ph)
{
	write_status("is sleeping.\n", ph);
	ft_usleep(ph->p_arg->time_s);
	write_status("is thinking\n", ph);
}

void	actions(t_philo	*ph)
{
	pthread_mutex_lock(&ph->l_fork);
	write_status("has taken a fork.\n", ph);
	if (!ph->r_fork)
	{
		ft_usleep(ph->p_arg->time_d);
		return ;
	}
	pthread_mutex_lock(ph->r_fork);
	write_status("has taken a fork.\n", ph);
	write_status("is eating.\n", ph);
	ph->ms_eat = actual_time();
	ft_usleep(ph->p_arg->time_e);
	pthread_mutex_unlock(ph->r_fork);
	pthread_mutex_unlock(&ph->l_fork);
	sleep_think(ph);
}

void	*thread(void *data)
{
	t_philo	*ph;

	ph = (t_philo *)data;
	if (ph->id % 2 == 0)
		ft_usleep(ph->p_arg->time_e / 10);
	while (!check_dead(ph, 0))
	{
		actions(ph);
		if (is_dead(ph))
			return (NULL);
		if ((int)++ph->nb_eat == ph->p_arg->m_eat)
		{
			pthread_mutex_lock(&ph->p_arg->finish);
			ph->finish = 1;
			ph->p_arg->nb_p_finish++;
			if (ph->p_arg->nb_p_finish == ph->p_arg->n_philos)
			{
				pthread_mutex_unlock(&ph->p_arg->finish);
				check_dead(ph, 2);
			}
			pthread_mutex_unlock(&ph->p_arg->finish);
			return (NULL);
		}
	}
	return (NULL);
}

int	threading(t_init *ini)
{
	int	i;

	i = 0;
	while (i < ini->arg.n_philos)
	{
		ini->philo[i].p_arg = &ini->arg;
		if (pthread_create(&ini->philo[i].thread_id, NULL, \
			thread, &ini->philo[i]) != 0)
			return (ext("Can't create a thread", i));
		i++;
	}
	return (0);
}

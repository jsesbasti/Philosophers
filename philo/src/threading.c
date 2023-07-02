/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 00:02:47 by jsebasti          #+#    #+#             */
/*   Updated: 2023/07/02 17:24:58 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*is_dead(void *data)
{
	t_philo	*ph;

	ph = (t_philo *)data;
	ft_usleep(ph->p_arg->time_d);
	pthread_mutex_lock(&ph->p_arg->time_eat);
	pthread_mutex_lock(&ph->p_arg->finish);
	if (!check_dead(ph, 0) && !ph->finish && ((actual_time() - ph->ms_eat) \
		>= (long)(ph->p_arg->time_d)))
	{
		pthread_mutex_unlock(&ph->p_arg->time_eat);
		pthread_mutex_unlock(&ph->p_arg->finish);
		pthread_mutex_lock(&ph->p_arg->write_mutex);
		write_status("died.\n", ph);
		pthread_mutex_unlock(&ph->p_arg->write_mutex);
		check_dead(ph, 1);
		return (NULL);
	}
	pthread_mutex_unlock(&ph->p_arg->time_eat);
	pthread_mutex_unlock(&ph->p_arg->finish);
	return (NULL);
}

void	sleep_think(t_philo *ph)
{
	pthread_mutex_lock(&ph->p_arg->write_mutex);
	write_status("is sleeping.\n", ph);
	pthread_mutex_unlock(&ph->p_arg->write_mutex);
	ft_usleep(ph->p_arg->time_s);
	pthread_mutex_lock(&ph->p_arg->write_mutex);
	write_status("is thinking\n", ph);
	pthread_mutex_unlock(&ph->p_arg->write_mutex);
}

void	actions(t_philo	*ph)
{
	pthread_mutex_lock(&ph->l_fork);
	pthread_mutex_lock(&ph->p_arg->write_mutex);
	write_status("has taken a fork.\n", ph);
	pthread_mutex_unlock(&ph->p_arg->write_mutex);
	if (!ph->r_fork)
	{
		ft_usleep(ph->p_arg->time_d * 2);
		return ;
	}
	pthread_mutex_lock(ph->r_fork);
	pthread_mutex_lock(&ph->p_arg->write_mutex);
	write_status("has taken a fork.\n", ph);
	pthread_mutex_unlock(&ph->p_arg->write_mutex);
	pthread_mutex_lock(&ph->p_arg->write_mutex);
	write_status("is eating.\n", ph);
	pthread_mutex_unlock(&ph->p_arg->write_mutex);
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
		pthread_create(&ph->thread_death_id, NULL, is_dead, data);
		actions(ph);
		pthread_detach(ph->thread_death_id);
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

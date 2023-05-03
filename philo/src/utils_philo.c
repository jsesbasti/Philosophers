/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 00:34:55 by jsebasti          #+#    #+#             */
/*   Updated: 2023/05/03 02:42:27 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_status(char *str, t_philo *ph)
{
	long int		time;

	time = -1;
	time = actual_time() - ph->p_arg->start_t;
	if (time >= 0 && time <= 2147483647 && !check_dead(ph, 0))
	{
		printf("%ld ", time);
		printf("Philo %d %s", ph->id, str);
	}
}

void	ft_usleep(long int time)
{
	long int	start_time;

	start_time = 0;
	start_time = actual_time();
	while ((actual_time() - start_time) < time)
		usleep(time / 10);
}

long int	actual_time(void)
{
	long int			time;
	struct timeval		current_time;

	time = 0;
	if (gettimeofday(&current_time, NULL) == -1)
		return (ext("Gettimeofday returned -1\n"));
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

int	check_dead(t_philo *ph, int i)
{
	pthread_mutex_lock(&ph->p_arg->dead);
	if (i)
		ph->p_arg->stop = i;
	if (ph->p_arg->stop)
	{
		pthread_mutex_unlock(&ph->p_arg->dead);
		return (1);
	}
	pthread_mutex_unlock(&ph->p_arg->dead);
	return (0);
}
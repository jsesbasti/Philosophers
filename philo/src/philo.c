/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 00:59:13 by jsebasti          #+#    #+#             */
/*   Updated: 2023/07/04 21:33:10 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ext(char *str, int id)
{
	ft_putstr_fd(str, 2);
	if (id)
		printf("%d\n", id);
	return (1);
}

int	check_dead2(t_init *ini)
{
	pthread_mutex_lock(&ini->arg.dead);
	if (ini->arg.stop)
	{
		pthread_mutex_unlock(&ini->arg.dead);
		return (1);
	}
	pthread_mutex_unlock(&ini->arg.dead);
	return (0);
}

void	stop(t_init *ini)
{
	int	i;

	i = -1;
	while (!check_dead2(ini))
		ft_usleep(1);
	while (++i < ini->arg.n_philos)
		pthread_join(ini->philo[i].thread_id, NULL);
	pthread_mutex_destroy(&ini->arg.write_mutex);
	i = -1;
	while (++i < ini->arg.n_philos)
		pthread_mutex_destroy(&ini->philo[i].l_fork);
	if (ini->arg.stop == 2)
		printf("Each philosopher ate %d time(s)\n", ini->arg.m_eat);
	free(ini->philo);
}

int	main(int ac, char **av)
{
	t_init	ini;

	if (check_args(ac, av, &ini))
		return (ext("Invalid args\n", 0));
	ini.philo = malloc(sizeof(t_philo) * ini.arg.n_philos);
	if (!ini.philo)
		return (ext("No philos allocated", 0));
	if (initialize(&ini) != 0 || threading(&ini) != 0)
	{
		free(ini.philo);
		return (ext("Error innitializing", 0));
	}
	stop(&ini);
}

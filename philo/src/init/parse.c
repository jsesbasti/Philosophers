/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:53:34 by jsebasti          #+#    #+#             */
/*   Updated: 2023/07/02 16:44:01 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	check_args(int ac, char **av, t_init *ini)
{
	t_args	*vars;

	vars = &ini->init_vars;
	if ((ac == 5 || ac == 6) && ft_strdigit(av))
	{
		vars->num_philos = ft_atoi(av[1]);
		vars->time_die = ft_atoi(av[2]);
		vars->time_eat = ft_atoi(av[3]);
		vars->time_sleep = ft_atoi(av[4]);
		if (ac == 6)
		{
			vars->must_eat = ft_atoi(av[5]);
			if (vars->must_eat == 0)
				return (ext("They can't eat 0 times\n", 0));
		}
		if (vars->num_philos <= 0 || vars->time_die <= 0 || \
			vars->time_eat <= 0 || vars->time_sleep <= 0)
			return (false);
		return (true);
	}
	return (false);
}

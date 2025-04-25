/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-25 15:53:54 by jsebasti          #+#    #+#             */
/*   Updated: 2025-04-25 15:53:54 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_init	ini;
	t_args	*vars;

	vars = &ini.init_vars;
	if (check_args(ac, av, &ini) == false)
		return (ext("Invalid args\n", 0));
	ini.philos = ft_calloc(sizeof(t_philo), vars->num_philos);
	if (!ini.philos)
		return (ext("No philos allocated", 0));
	if (initialize(&ini) != 0 || threading(&ini) != 0)
	{
		free(ini.philos);
		return (ext("Error innitializing", 0));
	}
	stop(&ini);
}

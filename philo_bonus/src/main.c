/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:07:58 by jsebasti          #+#    #+#             */
/*   Updated: 2023/05/04 19:50:02 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ext(char *s, int fd)
{
	write(fd, s, sizeof(char) * ft_strlen(s));
	return (1);
}

int	main(int ac, char **av)
{
	t_init	p;

	if (check_args(ac, av, &p))
		return (ext("Args error.\n", 2));
	p.philo = malloc(sizeof(t_philo) * p.arg.total)
	if (!p.philo)
		return (ext("Can't allocate memory.\n", 2));
	if (initialize(&p))
		return (ext("Can't initialize", 2));
	return (0);
}

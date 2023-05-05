/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:07:47 by jsebasti          #+#    #+#             */
/*   Updated: 2023/05/04 19:46:10 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <semaphore.h>

typedef struct s_philo
{
	int	pid;


}	t_philo;

typedef struct s_args
{
	int	total;
	int	die;
	int	eat;
	int	sleep;
	int	m_eat;
}	t_args;

typedef struct s_init
{
	t_args	arg;
	t_philo	*phi;

}	t_init;

int	ft_atoi(char *str);

size_t	ft_strlen(char *str);

int	check_args(int ac, char **av, t_init *ini);

#endif
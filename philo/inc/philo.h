/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 01:06:34 by jsebasti          #+#    #+#             */
/*   Updated: 2023/05/04 19:00:45 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_args
{
	int				n_philos;
	int				time_d;
	int				time_e;
	int				time_s;
	int				m_eat;
	long int		start_t;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	dead;
	pthread_mutex_t	time_eat;
	pthread_mutex_t	finish;
	int				nb_p_finish;
	int				stop;
}	t_args;

typedef struct s_philo
{
	int					id;
	pthread_t			thread_id;
	pthread_t			thread_death_id;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		l_fork;
	t_args				*p_arg;
	long int			ms_eat;
	unsigned int		nb_eat;
	int					finish;
}	t_philo;

typedef struct s_init
{
	t_args	arg;
	t_philo	*philo;
}	t_init;

int			ext(char *str);

void		ft_putstr_fd(char *s, int fd);

size_t		ft_strlen(char *s);

int			ft_atoi(char *str);

int			check_args(int ac, char **av, t_init *ini);

int			initialize(t_init *ini);

long int	actual_time(void);

int			threading(t_init *ini);

void		ft_usleep(long int time);

int			check_dead(t_philo *ph, int i);

void		write_status(char *str, t_philo *ph);

#endif

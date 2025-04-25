/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 01:06:34 by jsebasti          #+#    #+#             */
/*   Updated: 2023/07/04 21:35:02 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

# define ERROR 1
# define SUCCESS 0

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_args
{
	unsigned int	num_philos;
	unsigned int	time_die;
	unsigned int	time_eat;
	unsigned int	time_sleep;
	unsigned int	must_eat;
	long int		start_time;
}	t_args;

typedef struct s_philo
{
	unsigned int		id;
	pthread_t			thread_id;
	pthread_mutex_t		r_fork;
	pthread_mutex_t		*l_fork;
	unsigned int		nb_eat;
	int					finished;

}	t_philo;

typedef struct s_init
{
	t_args	init_vars;
	t_philo	*philos;
	pthread_mutex_t	print_mtx;
}	t_init;

int				ext(char *str, int id);

void			ft_putstr_fd(char *s, int fd);

size_t			ft_strlen(char *s);

t_bool			ft_isdigit(char c);

unsigned int	ft_atoi(char *str);

void			*ft_calloc(size_t count, size_t size);

t_bool			check_args(int ac, char **av, t_init *ini);

int				initialize(t_init *ini);

long int		actual_time(void);

int				threading(t_init *ini);

void			ft_usleep(long int time);

int				check_dead(t_philo *ph, int i);

void			write_status(char *str, t_philo *ph);

#endif

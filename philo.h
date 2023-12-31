/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:36:26 by jaeshin           #+#    #+#             */
/*   Updated: 2023/10/04 11:08:58 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

# define FORK 0
# define EAT 1
# define SLEEP 2
# define THINK 3
# define DIE 4

typedef struct s_fork {
	int				id;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_args {
	int				nbr_of_phil;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_must_eat;
	int				total_nbr_eat;
	long long		start_time;
	t_fork			*forks;
	pthread_mutex_t	print;
}	t_args;

typedef struct s_philo {
	pthread_t	thread;
	int			flag;
	int			id;
	int			l_fork;
	int			r_fork;
	long long	last_meal;
	int			count_of_eat;
	t_args		*args;
}	t_philo;

typedef struct s_total {
	t_fork		*forks;
	t_args		*args;
	t_philo		*philos;
}	t_total;

// INIT
t_total		*init_total(int argc, char **argv);
void		init_err(t_total *total);

// THREAD
void		*thread_func(void *philo);
void		*watcher(void *philos);
void		create_run_thread(t_total *total);
void		destroy_mutex(t_total *total);

// ACTIONS
int			philo_eat(t_philo *p);
void		philo_sleep(t_philo *p);
void		philo_think(t_philo *p);

// PRINT
void		print_action(t_philo *p, long long start_time, int state);
void		print_if_all_eaten(t_total *total);

// UTILES
void		free_memory(t_total *total);
long long	get_time(void);
int			ft_usleep(long long time);
int			ft_atoi(const char *str);

#endif

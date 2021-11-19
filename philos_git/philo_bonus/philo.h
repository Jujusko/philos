/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faggar <faggar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:50:14 by faggar            #+#    #+#             */
/*   Updated: 2021/10/12 11:44:52 by faggar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <semaphore.h>
# include <stdio.h>
# include <pthread.h>
# include <signal.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# define ALL_FCK 123
# define ALL_EATEN 229
typedef struct s_philo
{
	int				last_eat;
	int				start_time;
	int				philo_numb;
	int				eat_until;
	int				eat_count;
	int				die_inf;
	sem_t			*fork_1;
	sem_t			*fork_2;
	sem_t			*print;
	pid_t			this_pid;
	pthread_t		thread;
	struct s_main	*main_struct;
}t_philo;

typedef struct s_main
{
	int		amount_philos;
	int		live_inf;
	int		eat_inf;
	int		count_eat;
	int		sleep_inf;
	sem_t	*forks;
	sem_t	*print;
	sem_t	*wait_all;
	t_philo	*philos;

	int		start_time;
}t_main;

int		read_args(t_main *a, char **av, int ac);
//		ACTIONS
void	forks(t_philo *phil, int now);
void	eat(t_philo *phil, int now);
void	another_thing(t_philo *phil, int now);
//		TIME
int		get_time(void);
void	my_usleep(int sleep);

void	fill_philo(t_main *a);
void	make_processes(t_main *a);

#endif
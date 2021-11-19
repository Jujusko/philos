/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faggar <faggar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 18:18:19 by faggar            #+#    #+#             */
/*   Updated: 2021/09/28 13:35:30 by faggar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <sys/time.h>

typedef struct s_phil_info
{
	int				philo_numb;
	int				numb_mod_2;
	int				last_eat;
	int				sleep_inf;
	int				live_inf;
	int				eat_inf;
	int				start_time_p;
	int				eat_counter;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*print;
	pthread_t		i;
}t_phil_info;

typedef struct s_info
{
	int				start_time;
	int				phil_numbs;
	int				eat_inf;
	int				sleep_inf;
	int				live_info;
	int				eat_count;
	pthread_mutex_t	*eat;
	t_phil_info		*phils;
	pthread_mutex_t	*forks;
}t_info;

typedef struct s_main
{
	struct timeval	cur_time;
	int				re;
	int				times;
	int				now;
}t_main;

int		get_time(void);
void	my_usleep(int sleep);

int		read_args(t_info *pes, char **av, int ac);
void	another_thing(t_phil_info *phil, int now);
void	eat(t_phil_info *phil, int now);
void	forks(t_phil_info *phil, int now);
void	forks_1(t_phil_info *phil, int now);
int		monitor(t_info *pes, t_main i);

#endif
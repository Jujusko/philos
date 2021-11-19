/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faggar <faggar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 18:17:51 by faggar            #+#    #+#             */
/*   Updated: 2021/11/19 15:13:57 by faggar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	forks(t_phil_info *phil, int now)
{
	pthread_mutex_lock(phil->l_fork);
	pthread_mutex_lock(phil->print);
	now = get_time() - phil->start_time_p;
	printf("%d	%d	taken fork\n", now, phil->philo_numb);
	pthread_mutex_unlock(phil->print);
	pthread_mutex_lock(phil->r_fork);
	pthread_mutex_lock(phil->print);
	now = get_time() - phil->start_time_p;
	printf("%d	%d	taken fork\n", now, phil->philo_numb);
	pthread_mutex_unlock(phil->print);
}

void	forks_1(t_phil_info *phil, int now)
{
	pthread_mutex_lock(phil->r_fork);
	pthread_mutex_lock(phil->print);
	now = get_time() - phil->start_time_p;
	printf("%d	%d	taken fork\n", now, phil->philo_numb);
	pthread_mutex_unlock(phil->print);
	pthread_mutex_lock(phil->l_fork);
	pthread_mutex_lock(phil->print);
	now = get_time() - phil->start_time_p;
	printf("%d	%d	taken fork\n", now, phil->philo_numb);
	pthread_mutex_unlock(phil->print);
}

void	eat(t_phil_info *phil, int now)
{
	phil->last_eat = get_time() - phil->start_time_p;
	pthread_mutex_lock(phil->print);
	printf("%d	%d	is eating\n", now, phil->philo_numb);
	phil->last_eat = now;
	pthread_mutex_unlock(phil->print);
	my_usleep(phil->eat_inf);
	if (phil->numb_mod_2 != 1)
	{
		pthread_mutex_unlock(phil->l_fork);
		pthread_mutex_unlock(phil->r_fork);
	}
	else
	{
		pthread_mutex_unlock(phil->r_fork);
		pthread_mutex_unlock(phil->l_fork);
	}
	now = get_time() - phil->start_time_p;
}

void	another_thing(t_phil_info *phil, int now)
{
	now = get_time() - phil->start_time_p;
	pthread_mutex_lock(phil->print);
	printf("%d	%d	is sleeping\n", now, phil->philo_numb);
	pthread_mutex_unlock(phil->print);
	my_usleep(phil->sleep_inf);
	now = get_time() - phil->start_time_p;
	pthread_mutex_lock(phil->print);
	printf("%d	%d	is thinking\n", now, phil->philo_numb);
	pthread_mutex_unlock(phil->print);
}

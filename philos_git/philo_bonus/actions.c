/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faggar <faggar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 18:17:51 by faggar            #+#    #+#             */
/*   Updated: 2021/10/08 15:49:56 by faggar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	forks(t_philo *phil, int now)
{
	sem_wait(phil->fork_1);
	sem_wait(phil->print);
	printf("%d %d taken fork\n", now, phil->philo_numb);
	sem_post(phil->print);
	sem_wait(phil->fork_2);
	now = get_time() - phil->main_struct->start_time;
	sem_wait(phil->print);
	printf("%d %d taken fork\n", now, phil->philo_numb);
	sem_post(phil->print);
}

void	eat(t_philo *phil, int now)
{
	phil->last_eat = get_time() - phil->main_struct->start_time;
	sem_wait(phil->print);
	phil->die_inf = now + phil->main_struct->live_inf;
	printf("%d %d is eating\n", now, phil->philo_numb);
	phil->last_eat = now;
	sem_post(phil->print);
	my_usleep(phil->main_struct->eat_inf);
	sem_post(phil->fork_1);
	sem_post(phil->fork_2);
	now = get_time() - phil->main_struct->start_time;
}

void	another_thing(t_philo *phil, int now)
{
	now = get_time() - phil->main_struct->start_time;
	printf("%d %d is sleeping\n", now, phil->philo_numb);
	my_usleep(phil->main_struct->sleep_inf);
	now = get_time() - phil->main_struct->start_time;
	printf("%d %d is thinking\n", now, phil->philo_numb);
}

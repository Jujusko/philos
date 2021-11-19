/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faggar <faggar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:40:00 by faggar            #+#    #+#             */
/*   Updated: 2021/10/18 14:41:51 by faggar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	body_monitor(t_philo *phil, int now)
{
	sem_wait(phil->print);
	usleep(100);
	if (phil->eat_count == -1 || phil->eat_count > 0)
	{
		printf("%d %d dead\n", now, phil->philo_numb);
		sem_post(phil->main_struct->wait_all);
		exit(1);
	}
	if (phil->eat_count > 0)
	{
		sem_post(phil->main_struct->wait_all);
		exit(ALL_FCK);
	}
}

void	*monitor(void *philosoph)
{
	t_philo	*phil;
	int		now;
	int		flag;

	flag = 1;
	phil = (t_philo *)philosoph;
	pthread_detach(phil->thread);
	now = get_time() - phil->main_struct->start_time - phil->last_eat;
	while (flag)
	{
		now = get_time() - phil->main_struct->start_time - phil->last_eat;
		if (now > phil->main_struct->live_inf)
			body_monitor(phil, now);
		else
			usleep(100);
	}
	return (NULL);
}

int	process_life(t_philo *phil)
{
	int	now;

	now = get_time() - phil->main_struct->start_time;
	pthread_create(&phil->thread, NULL, &monitor, (void *)phil);
	while (phil->eat_count != 0)
	{
		now = get_time() - phil->main_struct->start_time;
		forks(phil, now);
		now = get_time() - phil->main_struct->start_time;
		eat(phil, now);
		now = get_time() - phil->main_struct->start_time;
		another_thing(phil, now);
		if (phil->eat_count > 0)
			phil->eat_count--;
		if (phil->eat_count == 0)
		{
			sem_post(phil->main_struct->wait_all);
			free(phil->main_struct->philos);
			free(phil->main_struct);
			exit(1);
		}
	}
	return (0);
}

void	make_processes(t_main *a)
{
	int	i;
	int	pid;

	i = 0;
	while (i < a->amount_philos)
	{
		a->philos[i].this_pid = fork();
		if (a->philos[i].this_pid < 0)
		{
			printf("ERROR\n");
			exit(-1);
		}
		if (a->philos[i].this_pid == 0)
		{
			pid = getpid();
			process_life(&a->philos[i]);
			break ;
		}
		i++;
	}
}

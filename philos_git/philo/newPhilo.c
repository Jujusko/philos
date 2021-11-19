/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newPhilo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faggar <faggar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:55:23 by faggar            #+#    #+#             */
/*   Updated: 2021/10/18 17:22:52 by faggar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_info *pes, int i, int flag)
{
	pes->phils[i].philo_numb = i + 1;
	pes->phils[i].l_fork = &pes->forks[i];
	if (flag == 1)
		pes->phils[i].r_fork = &pes->forks[i + 1];
	else
		pes->phils[i].r_fork = &pes->forks[0];
	pes->phils[i].start_time_p = pes->start_time;
	pes->phils[i].print = pes->eat;
	pes->phils[i].last_eat = 0;
	pes->phils[i].live_inf = pes->live_info;
	pes->phils[i].sleep_inf = pes->sleep_inf;
	pes->phils[i].eat_inf = pes->eat_inf;
	pes->phils[i].eat_counter = pes->eat_count;
	pes->phils[i].numb_mod_2 = (i % 2);
}

void	philo_info(t_info *pes)
{
	int	i;

	i = 0;
	pthread_mutex_init(pes->eat, NULL);
	while (i < pes->phil_numbs)
	{
		pthread_mutex_init(&pes->forks[i], NULL);
		i++;
	}
	i = 0;
	while (i + 1 < pes->phil_numbs)
	{
		init_philo(pes, i, 1);
		i++;
	}
	if (i + 1 == pes->phil_numbs)
		init_philo(pes, i, 0);
}

void	*manager(void *inf)
{
	t_phil_info		*phil;
	int				now;

	phil = (t_phil_info *)inf;
	now = get_time() - phil->start_time_p;
	phil->start_time_p = phil->start_time_p;
	while (phil->eat_counter != 0)
	{
		now = get_time() - phil->start_time_p;
		if (phil->numb_mod_2 != 1)
			forks(phil, now);
		else
			forks_1(phil, now);
		now = get_time() - phil->start_time_p;
		eat(phil, now);
		now = get_time() - phil->start_time_p;
		another_thing(phil, now);
		pthread_detach(phil->i);
		if (phil->eat_counter > 0)
			phil->eat_counter--;
		if (phil->eat_counter == 0)
			return (NULL);
	}
	return (NULL);
}

void	start_thread(t_info *p)
{
	int	i;

	i = 0;
	while (i < p->phil_numbs)
	{
		if ((i % 2) != 1)
		{
			pthread_create(&p->phils[i].i, NULL, &manager, &p->phils[i]);
		}
		i++;
	}
	i = 0;
	usleep(500);
	while (i < p->phil_numbs)
	{
		if (i % 2 == 1)
		{
			pthread_create(&p->phils[i].i, NULL, &manager, &p->phils[i]);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_info			*pes;
	t_main			i;

	i.re = 0;
	pes = malloc(sizeof(*pes));
	if (!pes)
		return (-1);
	if (ac >= 5 && ac <= 6)
	{
		if (read_args(pes, av, ac) == -1)
			return (-1);
	}
	else
		return (-1);
	pes->start_time = get_time();
	philo_info(pes);
	start_thread(pes);
	while (1)
	{
		if (monitor(pes, i) == -1)
			return (-1);
	}
}

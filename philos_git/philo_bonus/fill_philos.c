/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faggar <faggar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:37:18 by faggar            #+#    #+#             */
/*   Updated: 2021/10/18 14:44:39 by faggar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_main *pes, int i)
{
	pes->philos[i].philo_numb = i + 1;
	pes->philos[i].start_time = pes->start_time;
	pes->philos[i].print = pes->print;
	pes->philos[i].last_eat = 0;
	pes->philos[i].main_struct = pes;
	pes->philos[i].eat_count = pes->count_eat;
	pes->philos[i].fork_1 = pes->forks;
	pes->philos[i].fork_2 = pes->forks;
}

void	fill_philo(t_main *a)
{
	int	i;

	sem_unlink("forks");
	sem_unlink("print");
	a->forks = sem_open("forks", O_CREAT, 0644, a->amount_philos);
	a->print = sem_open("print", O_CREAT, 0644, 1);
	i = 0;
	while (i < a->amount_philos)
		init_philo(a, i++);
}

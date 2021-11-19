/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faggar <faggar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:54:51 by faggar            #+#    #+#             */
/*   Updated: 2021/09/28 13:34:22 by faggar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	monitor(t_info *pes, t_main i)
{
	i.re = 0;
	while (i.re < pes->phil_numbs)
	{
		i.now = get_time()
			- pes->phils[i.re].start_time_p - pes->phils[i.re].last_eat;
		if (i.now > pes->live_info)
		{
			i.now = get_time() - pes->phils[i.re].start_time_p;
			pthread_mutex_lock(pes->phils[i.re].print);
			usleep(500);
			if (pes->phils[i.re].eat_counter == -1
				|| pes->phils[i.re].eat_counter > 0)
				printf("%d	philo %d dead\n", i.now, i.re + 1);
			return (-1);
		}
		i.re++;
	}
	return (1);
}

int	get_time(void)
{
	struct timeval	a;
	int				now_time;

	gettimeofday(&a, NULL);
	now_time = a.tv_sec * 1000 + a.tv_usec / 1000;
	return (now_time);
}

void	my_usleep(int sleep)
{
	int	start;
	int	now;

	now = get_time() + sleep;
	start = get_time();
	while (now > start)
	{
		usleep(50);
		start = get_time();
	}
}

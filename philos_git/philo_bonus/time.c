/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faggar <faggar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:54:51 by faggar            #+#    #+#             */
/*   Updated: 2021/10/05 14:16:30 by faggar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

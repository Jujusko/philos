/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faggar <faggar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:45:38 by faggar            #+#    #+#             */
/*   Updated: 2021/10/18 17:29:15 by faggar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	secnd_main(int i, t_main *a)
{
	int	z;

	i = 0;
	while (i < a->amount_philos)
	{
		z = kill(a->philos[i].this_pid, SIGTERM);
		if (z != 0)
			i = 0;
		i++;
	}
}

int	main(int ac, char **av)
{
	t_main	*a;
	int		i;
	int		status;

	i = 0;
	status = 0;
	a = malloc(sizeof(t_main));
	sem_unlink("wait");
	a->wait_all = sem_open("wait", O_CREAT, 0644, 1);
	sem_wait(a->wait_all);
	if (!a)
		exit(-1);
	if (ac < 5 || ac > 6)
	{
		printf("wrong args\n");
		sem_close(a->wait_all);
		exit(1);
	}
	read_args(a, av, ac);
	fill_philo(a);
	make_processes(a);
	sem_wait(a->wait_all);
	secnd_main(i, a);
}

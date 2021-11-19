/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faggar <faggar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:53:24 by faggar            #+#    #+#             */
/*   Updated: 2021/09/28 14:02:43 by faggar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '+')
			return (-1);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *strr)
{
	int		i;
	int		res;
	int		zn;
	char	*str;

	str = (char *)strr;
	i = 0;
	res = 0;
	zn = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			zn = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * zn);
}

int	error_checker(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (check_arg(av[i]) == -1)
		{
			printf("Wrong params\n");
			return (-1);
		}
		i++;
	}
	return (1);
}

int	read_args(t_info *pes, char **av, int ac)
{
	if (error_checker(av) == -1)
		return (-1);
	pes->phil_numbs = ft_atoi(av[1]);
	pes->live_info = ft_atoi(av[2]);
	pes->eat_inf = ft_atoi(av[3]);
	pes->sleep_inf = ft_atoi(av[4]);
	if (ac == 6)
		pes->eat_count = ft_atoi(av[5]);
	else
		pes->eat_count = -1;
	pes->forks = malloc(sizeof(pthread_mutex_t) * pes->phil_numbs);
	pes->phils = malloc(sizeof(t_phil_info) * pes->phil_numbs);
	pes->eat = malloc(sizeof(pthread_mutex_t));
	if (!pes->forks || !pes->phils || !pes->eat)
		return (-1);
	return (1);
}

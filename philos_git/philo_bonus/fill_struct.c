/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faggar <faggar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:38:13 by faggar            #+#    #+#             */
/*   Updated: 2021/10/12 12:14:34 by faggar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

static int	error_checker(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (check_arg(av[i]) == -1)
		{
			printf("Wrong params§\n");
			exit(-1);
		}
		i++;
	}
	return (1);
}

int	read_args(t_main *a, char **av, int ac)
{
	if (error_checker(av) == -1)
		return (-1);
	a->amount_philos = ft_atoi(av[1]);
	a->live_inf = ft_atoi(av[2]);
	a->eat_inf = ft_atoi(av[3]);
	a->sleep_inf = ft_atoi(av[4]);
	a->start_time = get_time();
	if (ac == 6)
		a->count_eat = ft_atoi(av[5]);
	else
		a->count_eat = -1;
	a->philos = malloc(sizeof(t_philo) * a->amount_philos - 1);
	if (!a->forks || !a->philos || !a->print)
		return (-1);
	return (1);
}

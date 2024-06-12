/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:50:45 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/12 14:42:33 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_mutex_rigth(t_data **data, int len)
{
	int	i;

	i = 0;
	(*data)->forks = malloc(sizeof(t_fork) * len);
	if (!(*data)->forks)
		return ;
	while (i < len)
	{
		(*data)->forks[i].id = i;
		pthread_mutex_init(&(*data)->forks[i].mutex, NULL);
		i++;
	}
}

static void	philo_init(t_data **data, int len)
{
	int	i;

	i = 0;
	(*data)->philo = malloc(sizeof(t_philo) * len);
	if (!(*data)->philo)
		return ;
	pthread_mutex_init(&(*data)->security.mutex, NULL);
	while (i < len)
	{
		(*data)->philo[i].id = i + 1;
		(*data)->philo[i].nbr_meals = 0;
		(*data)->philo[i].out_of_time = false;
		(*data)->philo[i].last_meals = 0;
		(*data)->philo[i].data = (*data);
		(*data)->philo[i].fork_left = &(*data)->forks[(i + 1)
			% (*data)->nb_philo];
		(*data)->philo[i].fork_right = &(*data)->forks[i];
		i++;
	}
}

void	data_init(t_data **data, char **av, int ac)
{
	(*data)->nb_philo = ft_atoi(av[1]);
	(*data)->time_to_die = ft_atol(av[2]);
	(*data)->time_to_eat = ft_atol(av[3]);
	(*data)->time_to_sleep = ft_atol(av[4]);
	(*data)->dead_thread = false;
	start_timer(&(*data)->time_start);
	if ((*data)->time_to_die < 60 || (*data)->time_to_eat < 60
		|| (*data)->time_to_sleep < 60)
		return ;
	if (ac == 6)
		(*data)->nbr_of_meals = ft_atoi(av[5]);
	else
		(*data)->nbr_of_meals = -1;
	init_mutex_rigth(data, (*data)->nb_philo);
	pthread_mutex_init(&(*data)->deadlock, NULL);
	philo_init(data, (*data)->nb_philo);
}

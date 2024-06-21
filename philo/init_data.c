/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:22:11 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/18 10:11:56 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	init_time(t_time *time, char **str)
{
	time->time_to_died = m_atol(str[2]);
	time->time_to_eat = m_atol(str[3]);
	time->time_to_sleep = m_atol(str[4]);
	if ((time->time_to_died >= 60 && time->time_to_died <= INT_MAX)
		&& (time->time_to_sleep >= 60 && time->time_to_sleep <= INT_MAX)
		&& (time->time_to_eat >= 60 && time->time_to_eat <= INT_MAX))
		return (true);
	else
		return (false);
}

static bool	init_forks(t_data *data)
{
	int	i;
	int	j;

	data->forks_table = malloc(sizeof(t_forks) * data->nbr_philo);
	if (!data->forks_table)
		return (false);
	i = 0;
	while (i < data->nbr_philo)
	{
		data->forks_table[i].id = i + 1;
		if (pthread_mutex_init(&data->forks_table[i].mutex, NULL) != 0)
		{
			j = 0;
			while (j < i)
			{
				pthread_mutex_destroy(&data->forks_table[j].mutex);
				j++;
			}
			free(data->forks_table);
			return (false);
		}
		i++;
	}
	return (true);
}

void	fork_philo(t_data *data, int i)
{
	if (i == data->nbr_philo - 1 && data->nbr_philo % 2 != 0)
	{
		data->philo[i].left_fork = &data->forks_table[i];
		data->philo[i].rigth_fork = &data->forks_table[i - 1];
	}
	else
	{
		data->philo[i].left_fork = &data->forks_table[i];
		data->philo[i].rigth_fork = &data->forks_table[(i + 1)
			% data->nbr_philo];
	}
}

static bool	init_philo(t_data *data, int ac, char **str)
{
	int	i;

	i = -1;
	data->philo = malloc(sizeof(t_philo) * data->nbr_philo);
	if (!data->philo)
		return (false);
	while (++i < data->nbr_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].total_meals = 0;
		data->philo[i].last_meals = 0;
		if (ac == 6)
			data->philo[i].life.nbr_of_meals = m_atol(str[5]);
		else
			data->philo[i].life.nbr_of_meals = -1;
		if (!init_time(&data->philo[i].life, str) || (ac == 6
				&& !(data->philo[i].life.nbr_of_meals > 0
					&& data->philo[i].life.nbr_of_meals < INT_MAX)))
			return (free(data->forks_table), free(data->philo), false);
		data->philo[i].left_fork = &data->forks_table[i];
		data->philo[i].rigth_fork = &data->forks_table[(i + 1)
			% data->nbr_philo];
		data->philo[i].data = data;
	}
	return (true);
}

bool	init_data(t_data *data, char **av, int ac)
{
	if (ac == 5 || ac == 6)
	{
		data->nbr_philo = m_atol(av[1]);
		if (data->nbr_philo < 0 || data->nbr_philo > INT_MAX)
			return (false);
		if (!init_forks(data))
			return (false);
		if (!init_philo(data, ac, av))
			return (false);
		data->is_died = false;
		timer_start(&data->start_time);
		data->eating_count = 0;
		pthread_mutex_init(&data->mutex_print, NULL);
		pthread_mutex_init(&data->mutex_died, NULL);
		pthread_mutex_init(&data->mutex_time, NULL);
		pthread_mutex_init(&data->mutex_butler, NULL);
		pthread_mutex_init(&data->mutex_meals, NULL);
		pthread_mutex_init(&data->mutex_death, NULL);
		return (true);
	}
	else
		return (false);
}

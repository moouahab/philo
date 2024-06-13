/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 22:13:04 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/13 16:43:33 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine_one(void *arg)
{
	t_philo	*data;

	data = (t_philo *)arg;
	security_print(&(*data).data, "has taken a fork", data->id);
	usleep(data->data->time_to_die * 1e3);
	return (arg);
}

void	security_usleep(t_data *data, t_longi sleep_time)
{
	t_longi	interval;
	t_longi	slept_time;

	interval = 100;
	slept_time = 0;
	while (slept_time < sleep_time * 0.5)
	{
		usleep(interval);
		slept_time += interval;
		pthread_mutex_lock(&data->deadlock);
		if (data->dead_thread)
		{
			pthread_mutex_unlock(&data->deadlock);
			break ;
		}
		pthread_mutex_unlock(&data->deadlock);
	}
}

bool	monitor_time(t_philo *philo, t_longi current_time)
{
	bool	result;

	if (philo->data->philo->nbr_meals == philo->data->nbr_of_meals
		&& philo->data->philo->nbr_meals != -1)
		result = true;
	else if (current_time - philo->last_meals >= philo->data->time_to_die)
	{
		result = true;
		security_print(&philo->data, "\033[31mdied 1 \033[0m", philo->id);
	}
	else
		result = false;
	return (result);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	while (!security_data(&data, GET))
	{
		if (security_data(&data, GET_MEALS))
			break ;
		eat_meals(&philo, &data);
		if (security_data(&data, GET))
			break ;
		security_print(&data, "is sleeping", philo->id);
		security_usleep(data, data->time_to_sleep * 1000);
		if (security_data(&data, GET))
			break ;
		security_print(&data, "is thinking", philo->id);
	}
	return (NULL);
}

void	simulation(t_data **data)
{
	if ((*data)->nb_philo == 0)
		return ;
	if ((*data)->nb_philo == 1)
	{
		if (!thread_action(&(*data)->philo, routine_one, (*data)->nb_philo))
			return ((void)printf("Error : routine is not correct\n"));
	}
	else
	{
		if (!thread_action(&(*data)->philo, philo_routine, (*data)->nb_philo))
			return ((void)printf("Error : routine is not correct\n"));
	}
}

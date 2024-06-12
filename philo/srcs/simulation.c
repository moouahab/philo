/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 22:13:04 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/12 17:28:11 by moouahab         ###   ########.fr       */
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

void	ms_usplee(t_data	**data, size_t sleep_time)
{
	while (sleep_time)
	{
		if (security_data(data, GET))
			break ;
		usleep(30);
	}
}


bool	monitor_time(t_philo *philo, t_longi current_time)
{
	bool	result;

	if (current_time - philo->last_meals >= philo->data->time_to_die)
	{
		result = true;
		security_print(&philo->data, "\033[31mdied\033[0m", philo->id);
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
		ms_usplee(&data, data->time_to_sleep * 1000);
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

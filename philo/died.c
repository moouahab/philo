/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   died.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:37:06 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/18 19:36:22 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_death(t_data *data)
{
	bool	is_died;

	pthread_mutex_lock(&data->mutex_died);
	is_died = data->is_died;
	pthread_mutex_unlock(&data->mutex_died);
	return (is_died);
}

void	set_died(t_data *data)
{
	pthread_mutex_lock(&data->mutex_died);
	data->is_died = true;
	pthread_mutex_unlock(&data->mutex_died);
}

int	check_time_since_last_meal(t_data *data, int i)
{
	long	time_since_last_meal;

	pthread_mutex_lock(&data->mutex_time);
	time_since_last_meal = get_time_ms(data->start_time)
		- data->philo[i].last_meals;
	pthread_mutex_unlock(&data->mutex_time);
	if (time_since_last_meal >= (int)data->philo[i].life.time_to_died)
	{
		set_died(data);
		security_print(&data->philo[i], data, DIE);
		return (1);
	}
	return (0);
}

int	check_all_ate_enough(t_data *data)
{
	int	i;
	int	all_ate_enough;

	all_ate_enough = 1;
	i = 0;
	while (i < data->nbr_philo)
	{
		pthread_mutex_lock(&data->mutex_meals);
		if ((int)data->philo->life.nbr_of_meals != -1
			&& data->philo[i].total_meals < data->philo->life.nbr_of_meals)
			all_ate_enough = 0;
		pthread_mutex_unlock(&data->mutex_meals);
		i++;
	}
	return (all_ate_enough);
}

void	*monitor(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (1)
	{
		i = 0;
		while (i < data->nbr_philo)
		{
			if (check_time_since_last_meal(data, i))
				return (NULL);
			i++;
		}
		if ((int)data->philo->life.nbr_of_meals != -1
			&& check_all_ate_enough(data))
			return (set_died(data), NULL);
		usleep(500);
	}
	return (NULL);
}

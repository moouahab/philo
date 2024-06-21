/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:22:19 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/18 19:35:58 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_total_meals(t_philo *philo, t_data *data)
{
	bool	total_meals;

	total_meals = false;
	pthread_mutex_lock(&data->mutex_meals);
	if (philo->life.nbr_of_meals == philo->total_meals)
		total_meals = true;
	pthread_mutex_unlock(&data->mutex_meals);
	return (total_meals);
}

void	cleanup(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		pthread_mutex_destroy(&data->forks_table[i].mutex);
		i++;
	}
	pthread_mutex_destroy(&data->mutex_print);
	pthread_mutex_destroy(&data->mutex_died);
	pthread_mutex_destroy(&data->mutex_time);
	pthread_mutex_destroy(&data->mutex_butler);
	pthread_mutex_destroy(&data->mutex_meals);
	free(data->forks_table);
	free(data->philo);
}

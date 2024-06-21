/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thraed_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:30:32 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/19 15:19:45 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_one(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	security_print(philo, philo->data, FORK);
	return (NULL);
}

void	thread_start(t_data *data, void *(*f)(void *))
{
	int			i;
	pthread_t	monitor_thread;

	i = 0;
	while (i < data->nbr_philo)
	{
		if (pthread_create(&data->philo[i].th, NULL, f, &data->philo[i]))
			return ;
		i++;
	}
	pthread_create(&monitor_thread, NULL, monitor, data);
	i = 0;
	while (i < data->nbr_philo)
	{
		if (pthread_join(data->philo[i].th, NULL))
			return ;
		i++;
	}
	if (pthread_join(monitor_thread, NULL))
		return ;
}

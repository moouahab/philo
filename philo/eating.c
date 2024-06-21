/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:15:57 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/19 16:14:36 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	butler_permsion(t_data *data)
{
	pthread_mutex_lock(&data->mutex_butler);
	while (data->eating_count >= data->nbr_philo - 1)
	{
		pthread_mutex_unlock(&data->mutex_butler);
		usleep(100);
		pthread_mutex_lock(&data->mutex_butler);
	}
	data->eating_count++;
	pthread_mutex_unlock(&data->mutex_butler);
}

static void	philo_paritaire(t_philo *philo, t_data *data, t_forks *second_fork,
		t_forks *first_fork)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&first_fork->mutex);
		pthread_mutex_lock(&second_fork->mutex);
		security_print(philo, data, FORK);
	}
	else
	{
		usleep(philo->life.time_to_eat);
		pthread_mutex_lock(&second_fork->mutex);
		pthread_mutex_lock(&first_fork->mutex);
		security_print(philo, data, FORK);
	}
}

void	philo_paritaire_200(t_philo *philo, t_data *data, t_forks *second_fork,
		t_forks *first_fork)
{
	if (philo->id % 2 == 0)
	{
		usleep(data->nbr_philo);
		pthread_mutex_lock(&first_fork->mutex);
		pthread_mutex_lock(&second_fork->mutex);
		security_print(philo, data, FORK);
	}
	else
	{
		pthread_mutex_lock(&second_fork->mutex);
		pthread_mutex_lock(&first_fork->mutex);
		security_print(philo, data, FORK);
	}
}

static void	eat_thread(t_philo *philo, t_data *data, t_forks *second_fork,
		t_forks *first_fork)
{
	pthread_mutex_lock(&data->mutex_time);
	philo->last_meals = get_time_ms(data->start_time);
	pthread_mutex_unlock(&data->mutex_time);
	security_print(philo, data, EAT);
	usleep_thread(data->start_time, philo->life.time_to_eat, &data->is_died,
		&data->mutex_died);
	pthread_mutex_lock(&data->mutex_meals);
	philo->total_meals++;
	pthread_mutex_unlock(&data->mutex_meals);
	pthread_mutex_unlock(&first_fork->mutex);
	pthread_mutex_unlock(&second_fork->mutex);
	pthread_mutex_lock(&data->mutex_butler);
	data->eating_count--;
	pthread_mutex_unlock(&data->mutex_butler);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	while (1)
	{
		if (check_death(data) || check_total_meals(philo, data))
			break ;
		butler_permsion(data);
		philo_paritaire(philo, data, philo->left_fork, philo->rigth_fork);
		eat_thread(philo, data, philo->left_fork, philo->rigth_fork);
		if (check_death(data))
			break ;
		security_print(philo, data, SLEEP);
		usleep_thread(data->start_time, philo->life.time_to_sleep,
			&data->is_died, &data->mutex_died);
		security_print(philo, data, THINK);
		if (data->nbr_philo % 7 != 0 && data->nbr_philo != 3)
			usleep_thread(data->start_time, philo->life.time_to_eat
				- philo->life.time_to_sleep, &data->is_died, &data->mutex_died);
	}
	return (NULL);
}

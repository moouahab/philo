/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   security_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:21:51 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/19 12:38:10 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	security_print_eat(t_philo *philo, t_data *data, long current_time)
{
	if (check_death(data))
		return ((void)pthread_mutex_unlock(&data->mutex_print), false);
	printf("%ld %d is eating\n", current_time, philo->id);
	return (true);
}

bool	security_print_sleep(t_philo *philo, t_data *data, long current_time)
{
	if (check_death(data))
		return ((void)pthread_mutex_unlock(&data->mutex_print), false);
	printf("%ld %d is sleeping\n", current_time, philo->id);
	return (true);
}

bool	security_print_think(t_philo *philo, t_data *data, long current_time)
{
	if (check_death(data))
		return ((void)pthread_mutex_unlock(&data->mutex_print), false);
	printf("%ld %d is thinking\n", current_time, philo->id);
	return (true);
}

bool	security_print_fork(t_philo *philo, t_data *data, long current_time,
		t_action action)
{
	if (action == FORK)
	{
		if (check_death(data))
			return ((void)pthread_mutex_unlock(&data->mutex_print), false);
		printf("%ld %d has taken a fork\n", current_time, philo->id);
	}
	return (true);
}

void	security_print(t_philo *philo, t_data *data, t_action action)
{
	long	current_time;

	pthread_mutex_lock(&data->mutex_print);
	current_time = get_time_ms(data->start_time);
	if (action == EAT)
	{
		if (!security_print_eat(philo, data, current_time))
			return ;
	}
	else if (action == SLEEP)
	{
		if (!security_print_sleep(philo, data, current_time))
			return ;
	}
	else if (action == THINK)
	{
		if (!security_print_think(philo, data, current_time))
			return ;
	}
	else if (!security_print_fork(philo, data, current_time, action))
		return ;
	else if (action == DIE)
		if (check_death(data) && !check_total_meals(philo, data))
			printf("%ld %d died\n", current_time, philo->id);
	pthread_mutex_unlock(&data->mutex_print);
}

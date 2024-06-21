/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:21:44 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/19 11:14:57 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	timer_start(struct timeval *start_time)
{
	gettimeofday(start_time, NULL);
}

long	get_time_ms(struct timeval start_time)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec - start_time.tv_sec) * 1000 + (tv.tv_usec
			- start_time.tv_usec) / 1000);
}

void	usleep_thread(struct timeval start_time, unsigned long time_sleep,
		bool *is_died, pthread_mutex_t *mutex_died)
{
	unsigned long	start_time_ms;

	start_time_ms = get_time_ms(start_time);
	if (!(time_sleep > 0))
		time_sleep *= -1;
	while (get_time_ms(start_time) - start_time_ms < time_sleep)
	{
		usleep(100);
		pthread_mutex_lock(mutex_died);
		if (*is_died)
		{
			pthread_mutex_unlock(mutex_died);
			break ;
		}
		pthread_mutex_unlock(mutex_died);
	}
}

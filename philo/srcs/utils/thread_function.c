/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:25:14 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/13 16:45:23 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	thread_action(t_philo **t1, void *(*f)(void *), int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (pthread_create(&(*t1)[i].thread, NULL, f, &(*t1)[i]))
			return (false);
		i++;
	}
	check_thread_dead(t1);
	while (j < len)
	{
		if (pthread_join((*t1)[j].thread, NULL))
			return (false);
		j++;
	}
	return (true);
}

void	start_timer(struct timeval *start)
{
	gettimeofday(start, NULL);
}

t_longi	get_time(struct timeval *start)
{
	struct timeval	current;
	t_longi			elapsed_milliseconds;

	gettimeofday(&current, NULL);
	elapsed_milliseconds = (current.tv_sec - start->tv_sec) * 1000
		+ (current.tv_usec - start->tv_usec) / 1000;
	return (elapsed_milliseconds);
}

void	eat_meals(t_philo **philo, t_data **data)
{
	if ((*philo)->id % 2 == 0)
		lock_forks_even(philo, data);
	else
		lock_forks_odd(philo, data);
	if (check_deadlock(data))
		return ;
	security_print(data, "is eating", (*philo)->id);
	security_usleep(*data , (*data)->time_to_eat * 1e3);
	pthread_mutex_lock(&(*data)->deadlock);
	(*philo)->last_meals = get_time(&(*data)->time_start);
	(*philo)->nbr_meals++;
	pthread_mutex_unlock(&(*data)->deadlock);
	unlock_fork(&(*philo)->fork_left->mutex);
	unlock_fork(&(*philo)->fork_right->mutex);
}

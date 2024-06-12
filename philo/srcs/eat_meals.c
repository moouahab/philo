/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_meals.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 23:22:45 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/11 11:58:30 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_fork(pthread_mutex_t *mutex)
{
	if (pthread_mutex_lock(mutex) != 0)
		return ;
}

void	unlock_fork(pthread_mutex_t *mutex)
{
	if (pthread_mutex_unlock(mutex) != 0)
		return ;
}

int	check_deadlock(t_data **data)
{
	int	dead;

	pthread_mutex_lock(&(*data)->deadlock);
	dead = (*data)->dead_thread;
	pthread_mutex_unlock(&(*data)->deadlock);
	return (dead);
}

void	lock_forks_even(t_philo **philo, t_data **data)
{
	lock_fork(&(*philo)->fork_right->mutex);
	if (check_deadlock(data))
	{
		unlock_fork(&(*philo)->fork_right->mutex);
		return ;
	}
	security_print(data, "\033[33mhas taken a fork\033[0m", (*philo)->id);
	lock_fork(&(*philo)->fork_left->mutex);
	if (check_deadlock(data))
	{
		unlock_fork(&(*philo)->fork_right->mutex);
		unlock_fork(&(*philo)->fork_left->mutex);
		return ;
	}
	security_print(data, "\033[32mhas taken a fork\033[0m", (*philo)->id);
}

void	lock_forks_odd(t_philo **philo, t_data **data)
{
	usleep(5000);
	lock_fork(&(*philo)->fork_left->mutex);
	if (check_deadlock(data))
	{
		unlock_fork(&(*philo)->fork_left->mutex);
		return ;
	}
	security_print(data, "\033[33mhas taken a fork\033[0m", (*philo)->id);
	lock_fork(&(*philo)->fork_right->mutex);
	if (check_deadlock(data))
	{
		unlock_fork(&(*philo)->fork_left->mutex);
		unlock_fork(&(*philo)->fork_right->mutex);
		return ;
	}
	security_print(data, "\033[32mhas taken a fork\033[0m", (*philo)->id);
}

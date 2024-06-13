/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_meals.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 23:22:45 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/13 16:45:16 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void lock_fork(pthread_mutex_t *mutex)
{
    if (pthread_mutex_lock(mutex) != 0)
        return;
}

void unlock_fork(pthread_mutex_t *mutex)
{
    if (pthread_mutex_unlock(mutex) != 0)
        return;
}

int check_deadlock(t_data **data)
{
    int dead;

    pthread_mutex_lock(&(*data)->deadlock);
    dead = (*data)->dead_thread;
    pthread_mutex_unlock(&(*data)->deadlock);
    return dead;
}

void lock_forks_even(t_philo **philo, t_data **data)
{
    lock_fork(&(*philo)->fork_right->mutex);
    if (check_deadlock(data))
    {
        unlock_fork(&(*philo)->fork_right->mutex);
        return;
    }
    security_print(data, "\033[33mhas taken a fork\033[0m", (*philo)->id);
    lock_fork(&(*philo)->fork_left->mutex);
    if (check_deadlock(data))
    {
        unlock_fork(&(*philo)->fork_right->mutex);
        unlock_fork(&(*philo)->fork_left->mutex);
        return;
    }
    security_print(data, "\033[32mhas taken a fork\033[0m", (*philo)->id);
}

void lock_forks_odd(t_philo **philo, t_data **data)
{
    lock_fork(&(*philo)->fork_left->mutex);
	usleep(500);
    if (check_deadlock(data))
    {
        unlock_fork(&(*philo)->fork_left->mutex);
        return;
    }
    security_print(data, "\033[33mhas taken a fork\033[0m", (*philo)->id);
    lock_fork(&(*philo)->fork_right->mutex);
    if (check_deadlock(data))
    {
        unlock_fork(&(*philo)->fork_left->mutex);
        unlock_fork(&(*philo)->fork_right->mutex);
        return;
    }
    security_print(data, "\033[32mhas taken a fork\033[0m", (*philo)->id);
}

void eat_and_update(t_philo **philo, t_data **data)
{
    security_print(data, "is eating", (*philo)->id);
    security_usleep(*data, (*data)->time_to_eat * 1e3);

    pthread_mutex_lock(&(*data)->deadlock);
    (*philo)->last_meals = get_time(&(*data)->time_start);
    (*philo)->nbr_meals++;
    pthread_mutex_unlock(&(*data)->deadlock);
}

void unlock_forks(t_philo **philo)
{
    unlock_fork(&(*philo)->fork_left->mutex);
    unlock_fork(&(*philo)->fork_right->mutex);
}

// void eat_meals(t_philo **philo, t_data **data)
// {
//     if ((*philo)->id % 2 == 0)
//         lock_forks_even(philo, data);
//     else
//         lock_forks_odd(philo, data);
//     if (check_deadlock(data))
//         return;
//     eat_and_update(philo, data);
//     unlock_forks(philo);
// }


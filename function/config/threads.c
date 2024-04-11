/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:50:44 by moouahab          #+#    #+#             */
/*   Updated: 2024/04/11 03:08:43 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	my_create_thread(t_philo **philo, void *(*f)(void *))
{
	t_philo	*current_philo;

	current_philo = *philo;
	while (current_philo)
	{
		if (pthread_create(&(current_philo->philo), NULL, f,
				current_philo) != 0)
			return (msg_thread("create_philo failed"));
		current_philo = current_philo->next;
	}
	current_philo = *philo;
	while (current_philo)
	{
		if (pthread_join(current_philo->philo, NULL) != 0)
			return (msg_thread("join failed"));
		if (pthread_mutex_destroy(&current_philo->forks_r.fork_mutex) != 0)
			return (msg_mutex("destroy mutex forks right"));
		current_philo = current_philo->next;
	}
	return (true);
}


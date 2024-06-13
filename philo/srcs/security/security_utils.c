/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   security_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:52:02 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/13 16:44:42 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_security_data(t_data **data)
{
	if (pthread_mutex_init(&(*data)->security.mutex, NULL) != 0)
		return (ft_putstr_fd("\033[31mError : mutex_init", STDERR_FILENO));
	return (true);
}

bool	security_print(t_data **data, char *value, int id)
{
	if (pthread_mutex_lock(&(*data)->security.mutex) != 0)
		return (ft_putstr_fd("\033[31mError : mutex_lock", STDERR_FILENO));
	printf("%ld %d %s\n", get_time(&(*data)->time_start), id, value);
	if (pthread_mutex_unlock(&(*data)->security.mutex) != 0)
		return (ft_putstr_fd("\033[31mError : mutex_unlock", STDERR_FILENO));
	return (true);
}

bool	security_gett_value(t_data **data)
{
	if (pthread_mutex_lock(&(*data)->deadlock) != 0)
		return (ft_putstr_fd("\033[31mError : mutex_lock", STDERR_FILENO));
	if ((*data)->dead_thread)
	{
		if (pthread_mutex_unlock(&(*data)->deadlock) != 0)
			return (ft_putstr_fd("\033[31mError : mutex_unlock",
					STDERR_FILENO));
		return (true);
	}
	if (pthread_mutex_unlock(&(*data)->deadlock) != 0)
		return (ft_putstr_fd("\033[31mError : mutex_unlock", STDERR_FILENO));
	return (false);
}

bool	destroy_security_data(t_data **data)
{
	if (pthread_mutex_destroy(&(*data)->security.mutex) != 0)
		return (ft_putstr_fd("\033[31mError : mutex_destroy", STDERR_FILENO));
	return (true);
}

bool	security_gett_meals(t_data **data)
{
	if (pthread_mutex_lock(&(*data)->deadlock) != 0)
		return (ft_putstr_fd("\033[31mError : mutex_lock", STDERR_FILENO));
	if ((*data)->philo->nbr_meals == (*data)->nbr_of_meals
		&& (*data)->nbr_of_meals > -1)
	{
		if (pthread_mutex_unlock(&(*data)->deadlock) != 0)
			return (ft_putstr_fd("\033[31mError : mutex_unlock",
					STDERR_FILENO));
		return (true);
	}
	if (pthread_mutex_unlock(&(*data)->deadlock) != 0)
		return (ft_putstr_fd("\033[31mError : mutex_unlock", STDERR_FILENO));
	return (false);
}

// Fonction unique pour gérer les opérations
bool	security_data(t_data **data, t_operation_type op)
{
	if (op < INIT || op > DESTROY)
		return (ft_putstr_fd("\033[31mError : operation is not valid\n\033[0m",
				STDERR_FILENO));
	if (op == INIT)
		return (init_security_data(data));
	if (op == DESTROY)
		return (destroy_security_data(data));
	if (op == GET)
		return (security_gett_value(data));
	if (op == GET_MEALS)
		return (security_gett_meals(data));
	return (false);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:48:00 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/12 17:15:29 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	parse_data(char *data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		if (data[i] < '0' || data[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

void	check_thread_dead(t_philo **philo)
{
	while (!(*philo)->data->dead_thread)
		get_thread(philo);
}


bool	parsing(char **av, int ac, t_data **data)
{
	int	i;

	i = 1;
	if (ac < 5 || ac > 6)
		return (ft_putstr_fd("\033[31mError : argument to many\n\033[0m",
				STDERR_FILENO));
	while (av[i])
	{
		if (!parse_data(av[i]))
			return (ft_putstr_fd("\033[31mError : data corrupted\n\033[0m",
					STDERR_FILENO));
		i++;
	}
	data_init(data, av, ac);
	if ((*data)->time_to_die < 60 || (*data)->time_to_eat < 60
		|| (*data)->time_to_sleep < 60)
		return (ft_putstr_fd("\033[31mError : data corrupted\n\033[0m", 2));
	return (true);
}

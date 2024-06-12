/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:59:03 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/12 17:12:11 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/***
 * pour test le leaks est les dataraise
 * valgrind --tool=helgrind --history-level=approx ./philosophers 1 60 200 200
 */


/**
 * regalge du timestamp pour 5 300 60 600
 * cree un usplee() pour eviter un datarace
 * 
 * 
 * 
*/

int	main(int argc, char **argv)
{
	int		i;
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (-1);
	i = 0;
	if (parsing(argv, argc, &data))
	{
		simulation(&data);
		while (i < data->nb_philo)
		{
			if (pthread_mutex_destroy(&data->forks[i].mutex) != 0)
				return (-1);
			i++;
		}
		free(data->forks);
		free(data->philo);
		free(data);
	}
	else
		free(data);
	return (0);
}


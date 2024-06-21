/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:21:56 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/19 12:46:18 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//	printf("Initializing data\n");
// int i = 0;
// while (i < data.nbr_philo)
// {
// 	printf("philo: %d a la fourchette de droite numero %d et a ca gauche
// il a %d\n", data.philo[i].id,
// 		data.philo[i].rigth_fork->id, data.philo[i].left_fork->id);
//         i++;
// }

int	main(int argc, char *argv[])
{
	t_data	data;

	if (!init_data(&data, argv, argc))
	{
		printf("\033[31mError initializing data\033[0m\n");
		return (EXIT_FAILURE);
	}
	if (data.nbr_philo == 1)
		thread_start(&data, &philo_one);
	else if (data.nbr_philo == 200)
		thread_start(&data, &philo_routine_200);
	else
		thread_start(&data, &philo_routine);
	cleanup(&data);
	return (EXIT_SUCCESS);
}

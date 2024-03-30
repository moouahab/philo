/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:00:08 by moouahab          #+#    #+#             */
/*   Updated: 2024/03/30 15:53:13 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char const *argv[])
{
	t_table	table;

	if (parsin_philo(argc, argv, &table))
	{
		if (!lancement_simulation(&table))
		{
			free_philo(table.head);
			return (EXIT_FAILURE);
		}
		print_philo(table.head);
		free_philo(table.head);
	}
	return (0);
}

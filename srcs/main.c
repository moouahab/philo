/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:00:08 by moouahab          #+#    #+#             */
/*   Updated: 2024/04/11 13:06:02 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char const *argv[])
{
	t_table	table;

	if (parsin_philo(argc, argv, &table))
	{
		// 3) l'enceler la sumulation du dinner des philosophe
		// simulation_diner(&table);
		print_philo(table.head);
		free_philo(table.head);
	}
	return (0);
}

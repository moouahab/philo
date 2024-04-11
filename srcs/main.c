/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:00:08 by moouahab          #+#    #+#             */
/*   Updated: 2024/04/11 03:05:54 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char const *argv[])
{
	t_table	table;

    // 1) verifier l'inpute de utilisateur 
	// 2) initalisation des donne dans la liste chaine
	if (parsin_philo(argc, argv, &table))
	{
		// 3) l'enceler la sumulation du dinner des philosophe
		simulation_diner(&table);
		// print_philo(table.head);
		
		// 4) libre les resource qui sont malloc 
		free_philo(table.head);
	}
	return (0);
}

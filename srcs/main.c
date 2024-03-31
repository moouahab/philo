/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:00:08 by moouahab          #+#    #+#             */
/*   Updated: 2024/03/31 22:56:58 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char const *argv[])
{
	t_table	table;

	if (parsin_philo(argc, argv, &table))
	{
        // if (table.head->life.eat_count)
        // {
		//     if (!lancement_fini(&table))
		//     {
		// 	    free_philo(table.head);
		// 	    return (EXIT_FAILURE);
		//     }
        // }
        // else
        //     if (!lancement_philosophal(&table))
		//     {
		// 	    free_philo(table.head);
		// 	    return (EXIT_FAILURE);
		//     }
		my_create_thread(table.head, test_function);
		free_philo(table.head);
	}
	return (0);
}

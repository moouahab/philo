/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:43:30 by moouahab          #+#    #+#             */
/*   Updated: 2024/04/11 11:37:44 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	simulation_diner(t_table *table)
{
	t_philo	*philos;

	philos = table->head;
	if (table->place == 0)
		return ;
	if (table->place == 1)
		my_create_thread(&philos, one_philo);
	else
		my_create_thread(&philos, routine_philo);
}

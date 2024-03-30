/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lancement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:50:44 by moouahab          #+#    #+#             */
/*   Updated: 2024/03/30 15:51:14 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

void	*routine_philo(void *table)
{
	int		i;
	t_philo	*table_philo;

	i = 0;
	table_philo = (t_philo *)table;
	if (pthread_mutex_lock(&table_philo->mutex) != 0)
		return (msg_mutex2("table_philo"));
	while (i < table_philo->life.eat_count)
	{
		printf("je suis a la table des philo\n");
		i++;
	}
	if (pthread_mutex_unlock(&table_philo->mutex) != 0)
		return (msg_mutex2("table_philo"));
	return (NULL);
}

int	lancement_simulation(t_table *table)
{
	t_philo	*current_philo;

	current_philo = table->head;
	while (current_philo)
	{
		if (pthread_create(&current_philo->philo, NULL, routine_philo,
				current_philo) != 0)
			return (msg_thread("pthread_create"));
		usleep(10000);
		current_philo = current_philo->next;
	}
	current_philo = table->head;
	while (current_philo)
	{
		if (pthread_join(current_philo->philo, NULL) != 0)
			return (msg_thread("pthread_join"));
		if (pthread_mutex_destroy(&current_philo->mutex) != 0)
			return (msg_mutex("pthread_mutex_destroy"));
		current_philo = current_philo->next;
	}
	return (EXIT_SUCCESS);
}
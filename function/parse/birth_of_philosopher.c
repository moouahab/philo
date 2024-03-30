/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   birth_of_philosopher.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 21:48:07 by moouahab          #+#    #+#             */
/*   Updated: 2024/03/30 12:39:49 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_fork	init_fork(void)
{
	t_fork	fork;

	fork.left = true;
	fork.right = false;
	return (fork);
}

void	etap_init(t_philo **new_philo, int ac, char **data, int id)
{
	(*new_philo)->id = id;
	(*new_philo)->forks = init_fork();
	(*new_philo)->dead = false;
	(*new_philo)->eating = false;
	(*new_philo)->sleep = false;
	(*new_philo)->thinking = false;
    (*new_philo)->life = destinte_of_philo(ac, data);
}

void	free_philo(t_philo *philo)
{
	t_philo	*current;
	t_philo	*next;

	current = philo;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

t_philo	*birth_of_philosophers(int ac, char **data)
{
	int		i;
	t_philo	*philo;
	t_philo	*new_philo;
	t_philo	*last;

	philo = NULL;
	last = NULL;
	i = 0;
	while (i < atoi(data[1]))
	{
		new_philo = (t_philo *)malloc(sizeof(t_philo));
		if (!new_philo)
			return (t_philo *)(msg_allocation("new_philo"));
		etap_init(&new_philo, ac, data, i + 1);
        if (pthread_mutex_init(&new_philo->mutex, NULL) != 0)
            return NULL;
		new_philo->next = NULL;
		if (i == 0)
			philo = new_philo;
		else
			last->next = new_philo;
		last = new_philo;
		i++;
	}
	return (philo);
}



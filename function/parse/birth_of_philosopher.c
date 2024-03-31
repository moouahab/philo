/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   birth_of_philosopher.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 21:48:07 by moouahab          #+#    #+#             */
/*   Updated: 2024/03/31 18:53:17 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_fork	init_fork(void)
{
	t_fork	fork;

	 if (pthread_mutex_init(&fork.fork_mutex, NULL) != 0)
            return *(t_fork *)(msg_mutex2("mutex initialization error"));; 
	return (fork);
}

void	asigned_fork(t_philo	**new_philo, int id, int	philo_num)
{
	
	if ((*new_philo)->id % 2)
	{
		(*new_philo)->forks_l.id = id + 1 % philo_num;
		(*new_philo)->forks_r.id = id;
	}
	else
	{
		(*new_philo)->forks_l.id = (id + 1) % philo_num;
		(*new_philo)->forks_r.id = id;
	}
}

void	etap_init(t_philo **new_philo, int ac, char **data, int id)
{
	int        philo_num;
	
	philo_num = (int)atoli(data[1]);
	(*new_philo)->id = id;
	(*new_philo)->forks_r = init_fork();
	(*new_philo)->forks_l = init_fork();
	asigned_fork(new_philo, id, philo_num);
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



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   birth_of_philosopher.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 21:48:07 by moouahab          #+#    #+#             */
/*   Updated: 2024/04/11 03:18:46 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_fork	init_fork(void)
{
	t_fork	fork;

	if (pthread_mutex_init(&fork.fork_mutex, NULL) != 0)
		return (*(t_fork *)(msg_mutex2("mutex initialization error")));
	return (fork);
}

void assigned_forks(t_philo **new_philo, int id, int philo_num)
{
    if (id % 2)
    {
        (*new_philo)->forks_l.id = (id + 1) % philo_num;
        (*new_philo)->forks_r.id = id;
    }
    else
    {
        (*new_philo)->forks_l.id = (id + 1) % philo_num;
        (*new_philo)->forks_r .id = id;
    }
}

/**
 * Un philosophe a une fourchette dans un mutxe par fouchette
 * la fouchette d'autre aura un id est une creeation de fouchette
 * alors que la fouchette de gouche sera un pointer
 *
 * si id de droit  == id de gouche
 *
 * alore la dresse de la fouchette sera pointer
 *
 *
 */

void	init_fork_l(t_philo **philo)
{
	t_philo	*current_philo;
	t_philo	*new_fork_l;

	current_philo = *philo;
	while (current_philo)
	{
		new_fork_l = *philo;
		while (new_fork_l)
		{
			if (current_philo->forks_l.id == new_fork_l->forks_r.id)
			{
				current_philo->forks_l.fork_ptr = &new_fork_l->forks_r.fork_mutex;
				break ;
			}
			new_fork_l = new_fork_l->next;
		}
		current_philo = current_philo->next;
	}
	
}

static void	etap_init(t_philo **new_philo, int ac, char **data, int id)
{
	int	philo_num;

	philo_num = (int)atoli(data[1]);
	(*new_philo)->id = id + 1;
	(*new_philo)->life.nbr_meals = 0;
	(*new_philo)->forks_r = init_fork();
	assigned_forks(new_philo, id, philo_num);
	(*new_philo)->dead = false;
	(*new_philo)->life = destinte_of_philo(ac, data);
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
		etap_init(&new_philo, ac, data, i);
		new_philo->next = NULL;
		if (i == 0)
			philo = new_philo;
		else
			last->next = new_philo;
		last = new_philo;
		i++;
	}
	init_fork_l(&philo);
	return (philo);
}

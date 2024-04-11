/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:09:57 by moouahab          #+#    #+#             */
/*   Updated: 2024/04/11 11:36:52 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	storie_philo(t_philo *philo, char *str)
{
	philo->life.current_time = get_time(MILLISECOND) - philo->life.beginning;
	printf("%ld %d %s\n", philo->life.current_time, philo->id, str);
}

void	*one_philo(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	storie_philo(philo, "\033[33mhas taken a fork\033[0m");
	usleep(philo->life.time_to_die);
	storie_philo(philo, "\033[31mdied\033[0m");
	return (NULL);
}

// un philo meurt trois ca posible
// cas 1 : si il a manger tout ses repas
// cas 2 : si le temp de vie arrive sont terme
// cas 3 : si le temp d'antente entre chaque etat est trop long

// Fonction pour vérifier si le philosophe est mort
bool	is_dead(t_philo *philo)
{
	t_life		*life;
	long int	current_time;

	current_time = get_time(MILLISECOND);
	life = &philo->life;
	life->current_time = current_time;
	if (life->nbr_meals > 0 && life->meals_eaten >= life->nbr_meals)
	{
		printf("philosopher %d is dead because he has eaten all his meals.\n",
			philo->id);
		return (true);
	}
	if (current_time - life->last_meal_time >= life->time_to_die)
	{
		printf("philosopher %d is dead because he didn't eat in time.\n",
			philo->id);
		return (true);
	}
	if (current_time - life->last_sleep_time >= (life->time_to_sleep
			+ life->time_to_thinking))
	{
		printf("philosopher %d is dead waiting time between.\n", philo->id);
		return (true);
	}
	return (false);
}

void	*routine_philo(void *void_philo)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)void_philo;
	i = 0;
	while (i < 10)
	{
		storie_philo(philo, "\033[33mhas taken a fork\033[0m");
		pthread_mutex_lock(&philo->forks_r.fork_mutex);
		storie_philo(philo, "\033[33mhas taken a fork\033[0m");
		pthread_mutex_lock(philo->forks_l.fork_ptr);
		storie_philo(philo, "\033[32m is eating\033[0m");
		usleep(philo->life.time_to_eat);
		storie_philo(philo, "\033[34mis sleeping\033[0m");
		usleep(philo->life.time_to_sleep);
		storie_philo(philo, "\033[35mis thinking\033[0m");
		pthread_mutex_unlock(philo->forks_l.fork_ptr);
		pthread_mutex_unlock(&philo->forks_r.fork_mutex);
		i++;
	}
	storie_philo(philo, "\033[31mdied\033[0m");
	return (NULL);
}

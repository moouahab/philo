/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:10:46 by moouahab          #+#    #+#             */
/*   Updated: 2024/04/11 13:04:19 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	atoli(char const *str)
{
	long int	i;
	long int	res;

	res = 0;
	i = 0;
	while ((str[i] > 8 && str[i] < 14) && str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			return (msg_is_note_int());
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res);
}

void	print_life(t_life *life)
{
	printf("\n----------------------------------------\n\
la destin du philospher :\n\n\
\033[30m-   time_to_die =\033[0m %ld ms\n\
\033[32m-   time_to_eat =\033[0m %ld ms\n\
\033[35m-   time_to_sleep =\033[0m %ld ms\n\
-----------------------------------------\n\n",
		life->time_to_die, life->time_to_eat,
		life->time_to_sleep);
	if (life->nbr_meals != 0)
		printf("\n----------------------------------------\n\
-   combien repas doit-il manger :\n\n\
\033[30m-   number_of_times_each_philosopher_must_eat =\033[0m %d\n\
-----------------------------------------\n\n",
			life->nbr_meals);
}

void	print_philo(t_philo *data)
{
	t_philo	*philo;

	philo = data;
	while (philo)
	{
		printf("\n----------------------------------------\n\
\033[32m-  je suis le philosopher numero\033[0m %d\n\
-----------------------------------------\n\n",
			philo->id);
		printf("\n----------------------------------------\n\
\033[35m-  je suis la fouchette de droite numero\033[0m %d\n\
\033[33m-  je suis la fouchette de droite adress\033[0m %p\n\
-----------------------------------------\n\n",
			philo->forks_r.id, &philo->forks_r.fork_mutex);
		printf("\n----------------------------------------\n\
\033[34m-  je suis la fouchette de gauche numero\033[0m %d\n\
\033[33m-  je suis la fouchette de gauche adress\033[0m %p\n\
-----------------------------------------\n\n",
			philo->forks_l.id,
			philo->forks_l.fork_ptr);
		philo = philo->next;
	}
}

/*
** This function safely accesses shared data protected by a mutex.
** It either writes zeros to the data (if write_operation is true)
** or does nothing (if write_operation is false).
** Returns 1 on success and 0 on failure.
*/
int	safe_data_access(pthread_mutex_t *mutex, void *data, size_t size,
		int write_operation)
{
	int	lock_status;
	int	unlock_status;

	lock_status = pthread_mutex_lock(mutex);
	if (lock_status != 0)
		return (msg_mutex("lock_status failed"));
	if (write_operation)
		memset(data, 0, size);
	unlock_status = pthread_mutex_unlock(mutex);
	if (unlock_status != 0)
		return (msg_mutex("unlock_status failed"));
	return (true);
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

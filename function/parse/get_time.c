/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:34:04 by moouahab          #+#    #+#             */
/*   Updated: 2024/04/01 16:40:06 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * int rest_time(long  int rest_time)
 *
 * @param rest_time : le temp de repos en entre de  chaque activer
 * d'un philosopher
 *
 * @return : return temp de repos is successful en cas eurre = -1
 *
 */

bool	simulation_finished(t_table *table)
{
	t_philo	*current_philo;

	current_philo = table->head;
	while (current_philo)
	{
		if (current_philo->dead)
			return (true);
		current_philo = current_philo->next;
	}
	current_philo = table->head;
	while (current_philo)
	{
		if (current_philo->life.eat_count > 0)
			return (false);
		current_philo = current_philo->next;
	}
	return (true);
}

long int	get_time(t_code_time code)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
	{
		printf("Gettimeofday failed");
		return (-1);
	}
	if (MILLISECOND == code)
		return (tv.tv_sec * 1e3 + tv.tv_usec / 1e3);
	else if (MICROSECOND == code)
		return (tv.tv_sec * 1e6 + tv.tv_usec);
	else if (SECONDS == code)
		return (tv.tv_sec + tv.tv_usec / 1e6);
	return(0);
}

void	precise_usleep(long usec, t_table *table)
{
	long	start;
	long	elapsed;
	long	rem;

	start = get_time(MICROSECOND);
	while (get_time(MICROSECOND) - start < usec)
	{
		if (simulation_finished(table))
			break ;
		elapsed = get_time(MICROSECOND) - start;
		rem = usec - elapsed;
		if (rem > 1e6)
			usleep(rem / 2);
		else
			while (get_time(MICROSECOND) - start < usec)
				;
	}
}

void	storie_philo(long int time, int philosophical, char *etat)
{
	printf("%ld %d %s\n", time, philosophical, etat);
}

t_life	destinte_of_philo(int ac, char **str)
{
	t_life	life;

	life.eat_count = 0;
	life.time_to_die = atoli(str[2]) * 1e3;
	life.time_to_eat = atoli(str[3]) * 1e3;
	life.time_to_sleep = atoli(str[4]) * 1e3;
	if (ac == 6)
		life.eat_count = atoli(str[5]);
	return (life);
}

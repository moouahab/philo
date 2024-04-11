/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:34:04 by moouahab          #+#    #+#             */
/*   Updated: 2024/04/11 13:00:51 by moouahab         ###   ########.fr       */
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

long int	get_time(t_code_time code)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
	{
		printf("Gettimeofday failed");
		return (-1);
	}
	if (MILLISECOND == code)
		return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
	else if (MICROSECOND == code)
		return (tv.tv_sec * 1e6 + tv.tv_usec);
	else if (SECONDS == code)
		return (tv.tv_sec + tv.tv_usec / 1e6);
	return (0);
}

// void	precise_usleep(long usec, t_table *table)
// {
// 	long	start;
// 	long	elapsed;
// 	long	rem;

// 	start = get_time(MICROSECOND);
// 	while (get_time(MICROSECOND) - start < usec)
// 	{
// 		if (simulation_finished(table))
// 			break ;
// 		elapsed = get_time(MICROSECOND) - start;
// 		rem = usec - elapsed;
// 		if (rem > 1e6)
// 			usleep(rem / 2);
// 		else
// 			while (get_time(MICROSECOND) - start < usec)
// 				;
// 	}
// }

t_life	destinte_of_philo(int ac, char **str)
{
	t_life	life;
	long	current_time;

	current_time = get_time(MILLISECOND);
	if (current_time < 0)
		return (*(t_life *)msg_time("current_time is negative"));
	life.meals_eaten = 0;
	life.last_meal_time = 0;
	life.current_time = 0;
	life.beginning = current_time;
	life.time_to_die = atoli(str[2]) * 1e3;
	life.time_to_eat = atoli(str[3]) * 1e3;
	life.time_to_sleep = atoli(str[4]) * 1e3;
	if (ac == 6)
		life.nbr_meals = atoli(str[5]);
	return (life);
}

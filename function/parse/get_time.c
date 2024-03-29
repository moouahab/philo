/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:34:04 by moouahab          #+#    #+#             */
/*   Updated: 2024/03/29 21:42:23 by moouahab         ###   ########.fr       */
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

long	rest_time(long int rest_time)
{
	long int		margine;
	long int		elapsed;
	struct timeval	start;
	struct timeval	end;

	margine = 8;
	if (gettimeofday(&start, NULL) == -1)
		return (-1);
	usleep(rest_time * 1000);
	if (gettimeofday(&end, NULL) == -1)
		return (-1);
	elapsed = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec)
		/ 1000;
	return (elapsed + margine);
}

void    storie_philo(long int   time, int  philosophical, char  *etat)
{
    printf("%ld %d %s\n", time, philosophical, etat);
}

t_life    destinte_of_philo(int ac, char **str)
{
    t_life life;
    
	life.eat_count = 0;
    life.time_to_die = atoli(str[2]);
    life.time_to_eat = atoli(str[3]);
    life.time_to_sleep = atoli(str[4]);
	if (ac == 6)
		life.eat_count = atoli(str[5]);
    return (life);
}

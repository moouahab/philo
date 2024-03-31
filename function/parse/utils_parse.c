/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:10:46 by moouahab          #+#    #+#             */
/*   Updated: 2024/03/31 19:42:48 by moouahab         ###   ########.fr       */
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
			life->time_to_die,
			life->time_to_eat,
			life->time_to_sleep);
	if (life->eat_count != 0)
		printf("\n----------------------------------------\n\
-   combien repas doit-il manger :\n\n\
\033[30m-   number_of_times_each_philosopher_must_eat =\033[0m %d\n\
-----------------------------------------\n\n",
				life->eat_count);
}

void	print_philo(t_philo *data)
{
	t_philo *philo;

	philo = data;
	while (philo)
	{
		printf("\n----------------------------------------\n\
\033[32m-  je suis le philosopher numero\033[0m %d\n\
-----------------------------------------\n\n",
				philo->id);
		printf("\n----------------------------------------\n\
\033[35m-  je la fouchette de droite numero\033[0m %d\n\
-----------------------------------------\n\n",
				philo->forks_r.id);
		printf("\n----------------------------------------\n\
\033[34m-  je la fouchette de gauche numero\033[0m %d\n\
-----------------------------------------\n\n",
				philo->forks_l.id);
		philo = philo->next;
	}
}
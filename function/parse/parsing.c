/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:28:01 by moouahab          #+#    #+#             */
/*   Updated: 2024/04/09 00:15:55 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

/**
 * check_int_content :
 *
 * Cette fonction parcourt chaque caractère d'une chaîne de
 * caractères située dans un tableau de tableaux et vérifie
 * s'il ne contient que des caractères numériques.
 *
 */

bool	check_int_content(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!is_digit(av[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_overflower(char **av)
{
	int	i;

	i = 2;
	if (atoli(av[1]) > 200)
	{
		return (msg_not_args_valide(atoli(av[1])));
	}
	while (av[i])
	{
		if ((atoli(av[i]) < 60 || atoli(av[i]) > INT_MAX) && i < 5)
			return (msg_not_args_valide(atoli(av[i])));
		i++;
	}
	return (true);
}

int	parsin_philo(int ac, char const *av[], t_table *table)
{
	if ((ac <= 6 && ac >= 5) && check_int_content((char **)av))
	{
		if (!check_overflower((char **)av))
			return (false);
		else
		{
			printf("initialisation des donne de philo...\n");
			table->place = atoli(av[1]);
			table->head = birth_of_philosophers(ac, (char	**)av);
		}
	}
	else
	{
		if (!check_int_content((char **)av))
			return (msg_is_note_int());
		if (ac < 5 || ac > 6)
			return (msg_error_argument());
	}
	return (true);
}

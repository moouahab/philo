/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:28:01 by moouahab          #+#    #+#             */
/*   Updated: 2024/03/28 19:38:43 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

bool is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return(false);
}

// lim base a 60


/**
 * check_int_content :
 * 
 * Cette fonction parcourt chaque caractère d'une chaîne de 
 * caractères située dans un tableau de tableaux et vérifie
 * s'il ne contient que des caractères numériques.
 * 
*/

bool	check_int_content(char	**av)
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

bool	check_overflower(char	**av)
{
	int	i;

	i = 2;
    if (atomic(av[1]) > 200)
    {
        return msg_not_args_valide(atomic(av[1]));
    }
    while (av[i])
	{
		if ((atomic(av[i]) < 60 || atomic(av[i]) > INT_MAX) && i < 5)
			return msg_not_args_valide(atomic(av[i]));
		i++;
	}
	return (true);
}

int main(int argc, char const *av[])
{
    t_table table;
    
	if (argc == 6 && check_int_content((char **)av))
	{
		if (!check_overflower((char **)av))
            return (false);
        else
        {
            table.place = atomic(av[1]);
            printf("le nombre de place a la table des philosphe : %d\n", table.place);
        }
	}
	else
	{
		if (argc != 6)
			return  (msg_error_argument());
		if (!check_int_content((char **)av))
			return (msg_is_note_int());
	}
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:34:00 by moouahab          #+#    #+#             */
/*   Updated: 2024/04/11 11:38:45 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	msg_error_argument(void)
{
	printf("\n---------------------------------------------------------\n\
-  les argument rentre sont faut:\n\n\
-  \033[36mnumber_of_philosopher\033[0m\n\
-  \033[36mtime_to_die\033[0m\n\
-  \033[36mtime_to_eat\033[0m\n\
-  \033[36mtime_to_sleep\033[0m\n\
-  \033[36mnumber_of_times_each_philosopher_must_eat (optional)\033[0m\n\
---------------------------------------------------------\n\n");
	return (false);
}

bool	msg_is_note_int(void)
{
	printf("\n----------------------------------------------\n\
 -  \033[36mrentre des unsigned int en arg\033[0m\n\
----------------------------------------------\n\n");
	return (false);
}

bool	msg_not_args_valide(unsigned int n)
{
	printf("\n----------------------------------------------\n\
 -  \033[36m'%d' n'est pas accepter dans la plage des args\033[0m\n\
----------------------------------------------\n\n", n);
	return (false);
}

void	*msg_allocation(char *str)
{
	printf("\n----------------------------------------------\n\
 -  \033[36m'%s' : porblem d'allocation memoire \033[0m\n\
----------------------------------------------\n\n", str);
	return (NULL);
}

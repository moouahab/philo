/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_thread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 11:06:42 by moouahab          #+#    #+#             */
/*   Updated: 2024/04/09 12:43:54 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	msg_thread(char 	*str)
{
	printf("\n----------------------------------------------\n\
 -  \033[36'%s' Error de theards\033[0m\n\
----------------------------------------------\n\n", str);
    return (false);
}

bool	msg_mutex(char 	*str)
{
	printf("\n----------------------------------------------\n\
 -  \033[36'%s' Error de mutex\033[0m\n\
----------------------------------------------\n\n", str);
    return (false);
}

void	*msg_mutex2(char 	*str)
{
	printf("\n----------------------------------------------\n\
 -  \033[36'%s' Error de mutex\033[0m\n\
----------------------------------------------\n\n", str);
    return (NULL);
}

void	*msg_time(char 	*str)
{
	printf("\n----------------------------------------------\n\
 -  \033[36'%s'\033[0m\n\
----------------------------------------------\n\n", str);
    return (NULL);
}

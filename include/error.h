/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:41:01 by moouahab          #+#    #+#             */
/*   Updated: 2024/04/09 12:44:36 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "philo.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

void	*msg_time(char 	*str);
void	*msg_mutex2(char 	*str);
void	*msg_allocation(char *str);
bool	msg_not_args_valide(unsigned int n);
bool	msg_is_note_int(void);
bool	msg_error_argument(void);
bool	msg_thread(char *str);
bool	msg_mutex(char 	*str);

#endif
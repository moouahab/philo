/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:41:01 by moouahab          #+#    #+#             */
/*   Updated: 2024/03/30 01:22:12 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "philo.h"

void	*msg_allocation(char *str);
bool	msg_not_args_valide(unsigned int    n);
bool				msg_is_note_int(void);
bool				msg_error_argument(void);

#endif
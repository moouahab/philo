/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:34:01 by moouahab          #+#    #+#             */
/*   Updated: 2024/03/28 18:34:05 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "error.h"
# include <limits.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_life
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_think;
}					t_life;

typedef struct s_philo
{
	bool			dead;
	bool			sleep;
	bool			eating;
	bool			thinking;
	bool			fork_rigth;
	bool			fork_left;
	t_life			life;
	pthread_t		philo;
	pthread_mutex_t	mutex;

	struct s_philo	*next;
}					t_philo;

typedef struct s_table
{
	int				place;
	t_philo			*head;
    t_philo         *tail;

}					t_table;

// parsing functions
bool				check_int_content(char **av);
unsigned int		atomic(char const *str);

#endif

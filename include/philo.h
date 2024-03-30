/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:34:01 by moouahab          #+#    #+#             */
/*   Updated: 2024/03/30 15:54:38 by moouahab         ###   ########.fr       */
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
	int				eat_count;
	long int		time_to_die;
	long int		time_to_eat;
	long int		time_to_thinking;
	long int		time_to_sleep;
}					t_life;

typedef struct s_fork
{
	bool			right;
	bool			left;
}					t_fork;

typedef struct s_philo
{
	int				id;
	bool			dead;
	bool			sleep;
	bool			eating;
	bool			thinking;
	t_fork			forks;
	t_life			life;
	pthread_t		philo;
	pthread_mutex_t	mutex;
	struct s_philo	*next;
}					t_philo;

typedef struct s_table
{
	int				place;
	t_philo			*head;
}					t_table;

// parsing functions
bool				check_int_content(char **av);
long int			atoli(char const *str);
void				print_life(t_life *life);
int					parsin_philo(int ac, char const *av[], t_table *table);

void				print_philo(t_philo *philo);

// destinee function
t_philo				*birth_of_philosophers(int ac, char **data);
t_life				destinte_of_philo(int ac, char **str);
void				free_philo(t_philo *philo);

// function de confuguration 
int	lancement_simulation(t_table *table);
void	*routine_philo(void *table);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:34:01 by moouahab          #+#    #+#             */
/*   Updated: 2024/04/11 00:22:34 by moouahab         ###   ########.fr       */
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

typedef struct s_table	t_table;

typedef enum e_code_time
{
	SECONDS,
	MICROSECOND,
	MILLISECOND,
}						t_code_time;

typedef struct s_life
{
	t_code_time			time;
	int					nbr_meals;
	int					meals_eaten;     	// Nombre de repas que le philosophe a déjà mangés
	long int			last_meal_time; 	// Timestamp du dernier repas en millisecondes
    
	long int			current_time;		// Temps actuel (devrait être mis à jour régulièrement)
	long int			beginning;
	
	long int			time_to_die;
	long int			time_to_eat;
	long int			time_to_thinking;
	long int			time_to_sleep;
	long int			last_sleep_time;	// Timestamp du dernier sommeil en millisecondes
}						t_life;

typedef struct s_fork
{
	int					id;
	pthread_mutex_t		fork_mutex;
	pthread_mutex_t		*fork_ptr;
}						t_fork;

typedef struct s_philo
{
	int					id;
	bool				dead;
	t_fork				forks_r;
	t_fork				forks_l;
	t_life				life;
	t_table				*table;
	pthread_t			philo;
	struct s_philo		*next;
}						t_philo;

struct					s_table
{
	int					place;
	t_philo				*head;
};

void					*one_philo(void *void_philo);
void					*routine_philo(void *void_philo);
void					simulation_diner(t_table *table);
// parsing functions
bool					check_int_content(char **av);
long int				atoli(char const *str);
void					print_life(t_life *life);
int						parsin_philo(int ac, char const *av[], t_table *table);

void					print_philo(t_philo *philo);

// destinee function
t_philo					*birth_of_philosophers(int ac, char **data);
t_life					destinte_of_philo(int ac, char **str);
void					free_philo(t_philo *philo);

// function de confuguration
int						lancement_simulation(t_table *table);
void					*routine_philo(void *table);
void					storie_philo(t_philo *philo, char *str);

long int				get_time(t_code_time code_time);
bool					simulation_finished(t_table *table);
void					precise_usleep(long usec, t_table *table);

bool					my_create_thread(t_philo **philo, void *(*f)(void *));
void					*test_function(void *philo);

#endif

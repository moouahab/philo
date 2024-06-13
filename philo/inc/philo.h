/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:59:53 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/13 11:54:22 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef long int		t_longi;
typedef struct s_data	t_data;

// a mettre apres en normal
typedef struct s_security_data
{
	pthread_mutex_t		mutex;
}						t_security_data;

// Enumération pour les types d'opérations
typedef enum e_operation_type
{
	INIT,
	GET,
	GET_MEALS,
	DESTROY
}						t_operation_type;

typedef struct s_fork
{
	int					id;
	pthread_mutex_t		mutex;
}						t_fork;

typedef struct s_philo
{
	int					id;
	int					nbr_meals;
	bool				out_of_time;
	t_longi				last_meals;
	pthread_t			thread;
	t_fork				*fork_left;
	t_fork				*fork_right;
	t_data				*data;
}						t_philo;

struct					s_data
{
	int					nb_philo;
	int					nbr_of_meals;
	t_longi				time_to_die;
	t_longi				time_to_eat;
	t_longi				time_to_sleep;
	struct timeval		time_start;
	t_philo				*philo;
	t_fork				*forks;
	bool				dead_thread;
	pthread_mutex_t		deadlock;
	t_security_data		security;
};

// init des data
void					check_thread_dead(t_philo **philo);
void					security_usleep(t_data *data, t_longi sleep_time);
void					get_thread(t_philo **philo);
void					lock_forks_odd(t_philo **philo, t_data **data);
void					lock_forks_even(t_philo **philo, t_data **data);
int						check_deadlock(t_data **data);
void					lock_fork(pthread_mutex_t *mutex);
void					unlock_fork(pthread_mutex_t *mutex);
void					eat_meals(t_philo **philo, t_data **data);
bool					security_print(t_data **data, char *value, int i);
bool					monitor_time(t_philo *philo, t_longi current_time);
bool					parsing(char **av, int ac, t_data **data);
bool					security_data(t_data **data, t_operation_type op);
bool					thread_action(t_philo **t1, void *(*f)(void *),
							int len);
int						ft_atoi(char const *str);
void					data_init(t_data **data, char **av, int ac);
void					start_timer(struct timeval *start);
void					*ft_calloc(size_t num_elements, size_t element_size);
t_longi					get_time(struct timeval *start);
t_longi					ft_atol(const char *str);
void					simulation(t_data **data);
bool					ft_putstr_fd(char *str, int fd);

#endif
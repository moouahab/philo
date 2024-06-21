/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:21:39 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/19 12:44:26 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef enum e_action
{
	EAT,
	SLEEP,
	THINK,
	FORK,
	DIE
}						t_action;

typedef struct s_data	t_data;

typedef struct s_time
{
	unsigned long		time_to_died;
	unsigned long		time_to_eat;
	unsigned long		time_to_sleep;
	unsigned long		nbr_of_meals;
}						t_time;

typedef struct s_forks
{
	int					id;
	pthread_mutex_t		mutex;
}						t_forks;

typedef struct s_philo
{
	int					id;
	unsigned long		total_meals;
	unsigned long		last_meals;
	t_time				life;
	t_forks				*left_fork;
	t_forks				*rigth_fork;
	pthread_t			th;
	t_data				*data;

}						t_philo;

struct					s_data
{
	t_philo				*philo;
	t_forks				*forks_table;
	int					nbr_philo;
	struct timeval		start_time;
	int					eating_count;
	bool				is_died;
	pthread_mutex_t		mutex_print;
	pthread_mutex_t		mutex_died;
	pthread_mutex_t		mutex_time;
	pthread_mutex_t		mutex_meals;
	pthread_mutex_t		mutex_butler;
	pthread_mutex_t		mutex_death;
};

// function de transforamtion et parsing
bool					init_data(t_data *data, char **av, int ac);
unsigned long			m_atol(char const *str);
// function de la simulation
void					thread_start(t_data *data, void *(*f)(void *));
void					security_print(t_philo *philo, t_data *data,
							t_action action);
void					philo_paritaire_200(t_philo *philo, t_data *data,
							t_forks *second_fork, t_forks *first_fork);
// function gestion du temp
void					timer_start(struct timeval *start_time);
void					usleep_thread(struct timeval start_time,
							unsigned long time_sleep, bool *is_died,
							pthread_mutex_t *mutex_died);
long					get_time_ms(struct timeval start_time);
// routine
void					*philo_one(void *arg);
void					*philo_routine(void *arg);
void					*monitor(void *arg);
bool					check_death(t_data *data);
bool					check_total_meals(t_philo *philo, t_data *data);
void					*philo_routine_200(void *arg);
// free memory
void					cleanup(t_data *data);

#endif

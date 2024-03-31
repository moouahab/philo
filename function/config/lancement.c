/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lancement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:50:44 by moouahab          #+#    #+#             */
/*   Updated: 2024/03/31 22:55:30 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void    *test_function(void *philo)
{
    t_philo    *i;

    i = (t_philo *)philo;
    printf("je suis le philosopher n*%d\n", i->id);
    return (NULL);
}

void my_create_thread(t_philo *philo, void *(*f)(void *))
{
    t_philo *current_philo;

    current_philo = philo;
    while (current_philo)
    {
        if (pthread_create(&(current_philo->philo), NULL, f, current_philo) != 0)
            return;
        current_philo = current_philo->next;
    }
    current_philo = philo;
    while (current_philo)
    {
        if (pthread_join(current_philo->philo, NULL) != 0)
            return;
        if (pthread_mutex_destroy(&current_philo->forks_r.fork_mutex) != 0)
            return;
        if (pthread_mutex_destroy(&current_philo->forks_l.fork_mutex) != 0)
            return;
        current_philo = current_philo->next;
    }
}


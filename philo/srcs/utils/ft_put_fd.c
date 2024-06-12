/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 03:06:56 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/12 14:36:34 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

bool	ft_putstr_fd(char *str, int fd)
{
	if (!str)
		return (false);
	while (*str)
		ft_putchar_fd(*str++, fd);
	if (fd == STDERR_FILENO)
		return (false);
	else
		return (true);
}

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
	}
	else if (nb < 0 && nb > -2147483648)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
		ft_putnbr_fd(nb, fd);
	}
	else if (nb >= 0 && nb <= 9)
		ft_putchar_fd(nb + 48, fd);
	else if (nb > 9)
	{
		ft_putnbr_fd((nb / 10), fd);
		ft_putnbr_fd((nb % 10), fd);
	}
}

void	get_thread(t_philo **philo)
{
	int	i;

	i = 0;
	while (i < (*philo)->data->nb_philo)
	{
		if (pthread_mutex_lock(&(*philo)->data->deadlock) != 0)
			return ;
		if (monitor_time(&(*philo)[i], get_time(&(*philo)->data->time_start)))
		{
			(*philo)->data->dead_thread = 1;
			pthread_mutex_unlock(&(*philo)->data->deadlock);
			break ;
		}
		pthread_mutex_unlock(&(*philo)->data->deadlock);
		i++;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_atol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:22:07 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/18 14:24:12 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_argv(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (false);
		i++;
	}
	return (true);
}

unsigned long	m_atol(char const *str)
{
	unsigned long	prev_res;
	unsigned long	res;

	res = 0;
	prev_res = 0;
	if (!check_argv(str))
		return (-1);
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
		return ((unsigned long)-1);
	while (*str >= '0' && *str <= '9')
	{
		prev_res = res;
		res = res * 10 + (*str - '0');
		if (res < prev_res)
			return ((unsigned long)-1);
		str++;
	}
	return (res);
}

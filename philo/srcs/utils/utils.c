/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:20:11 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/12 14:39:18 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdint.h>

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	void	*ptr;

	if (element_size > 0 && SIZE_MAX / element_size < num_elements)
		return (NULL);
	ptr = malloc(num_elements * element_size);
	if (ptr == NULL)
		return (NULL);
	memset(ptr, 0, num_elements * element_size);
	return (ptr);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

bool	ft_checkoverflow(char const *str)
{
	const char	max_int[11] = "2147483647";
	int			slen;
	int			imaxlen;
	int			i;

	slen = ft_strlen(str);
	imaxlen = ft_strlen(max_int);
	if (*str == '-' || imaxlen < slen)
		return (0);
	if (imaxlen > slen)
		return (1);
	i = 0;
	while (max_int[i] && str[i])
	{
		if (max_int[i] < str[i])
			return (0);
		else if (max_int[i] > str[i])
			return (1);
		++i;
	}
	return (1);
}

int	ft_atoi(char const *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	if (!ft_checkoverflow(str))
		return (-1);
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (res * sign);
}

t_longi	ft_atol(const char *str)
{
	t_longi	res;
	t_longi	sign;

	res = 0;
	sign = 1;
	if (!ft_checkoverflow(str))
		return (-1);
	while ((*str < 14 && *str > 9) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}




/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:14:19 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/10 16:19:18 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#define LMAX LONG_MAX
#define LMIN LONG_MIN

static int	_isspace(int c)
{
	return ((9 <= c && c <= 13) || c == 32);
}

static int	_is_next_overflow(long int num, long int degit)
{
	return ((num > LMAX / 10) || (num == LMAX / 10 && degit > 7));
}

static int	_is_next_underflow(long int num, long int degit)
{
	return ((num < LMIN / 10) || (num == LMIN / 10 && degit < -8));
}

static long int	_strtol_base10(const char *nptr)
{
	long int	sign;
	long int	degit;
	long int	num;

	sign = 1;
	num = 0;
	while (_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	while (ft_isdigit(*nptr))
	{
		degit = *nptr - '0';
		if (_is_next_overflow(sign * num, sign * degit))
			return (LONG_MAX);
		if (_is_next_underflow(sign * num, sign * degit))
			return (LONG_MIN);
		num = num * 10 + degit;
		nptr++;
	}
	return (sign * num);
}

int	philo_atoi(const char *str)
{
	if (!str)
		return (0);
	return ((int)_strtol_base10(str));
}

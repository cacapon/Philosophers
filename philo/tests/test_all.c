/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:09:36 by ttsubo            #+#    #+#             */
/*   Updated: 2025/07/03 11:40:55 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"

void	setUp(void)
{
}

void	tearDown(void)
{
}

void	test_fork(void);
void	test_philo(void);

int	main(void)
{
	UNITY_BEGIN();
	test_fork();
	test_philo();
	return (UNITY_END());
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:09:36 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/07 12:51:37 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"

void	setUp(void)
{
}

void	tearDown(void)
{
}

void	test_queue(void);
void	test_fork(void);

int	main(void)
{
	UNITY_BEGIN();
	test_queue();
	test_fork();
	return (UNITY_END());
}
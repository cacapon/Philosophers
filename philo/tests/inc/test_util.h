/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_util.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 12:33:49 by ttsubo            #+#    #+#             */
/*   Updated: 2025/06/07 12:34:57 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_UTIL_H
# define TEST_UTIL_H

# include "unity.h"

# define RUN_PHILO_TEST(test_func) \
	do { setup(); RUN_TEST(test_func); teardown(); } while (0)

#endif 
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_ms.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 23:37:46 by emercier          #+#    #+#             */
/*   Updated: 2026/02/16 23:53:36 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	get_remaining(struct timeval now, long target)
{
	const long	now_us = now.tv_sec * 1000000L + now.tv_usec;

	return (target - now_us);
}

static long	get_chunk(long remaining)
{
	if (remaining > 10000)
		return (2000);
	else if (remaining > 2000)
		return (500);
	if (remaining < 100)
		return (remaining);
	else
		return (100);
}

void	sleep_ms(int ms)
{
	struct timeval	now;
	long			start;
	long			target;
	long			remaining;

	if (gettimeofday(&now, NULL) != 0)
		return ;
	start = now.tv_sec * 1000000L + now.tv_usec;
	target = start + (long)ms * 1000L;
	while (1)
	{
		if (gettimeofday(&now, NULL) != 0)
			return ;
		remaining = get_remaining(now, target);
		if (remaining <= 0)
			break ;
		usleep(get_chunk(remaining));
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 21:38:43 by emercier          #+#    #+#             */
/*   Updated: 2026/02/17 22:23:22 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	get_remaining(struct timeval now, long target_us)
{
	const long	now_us = now.tv_sec * 1000000L + now.tv_usec;

	return (target_us - now_us);
}

static long	get_chunk(long remaining_us)
{
	if (remaining_us > 2000)
		return (500);
	if (remaining_us < 100)
		return (remaining_us);
	else
		return (100);
}

// At this point a philosopher is never already dead, we just calculate
// if he will die during the sleeping time
static bool	is_enough_time(t_philosopher *p, long ms)
{
	const long	t = get_prop(&p->last_meal) + p->params.time_to_die - now_ms();

	if (t <= 0)
		return (false);
	if (ms >= t)
	{
		sleep_ms(t);
		return (false);
	}
	return (true);
}

void	philo_spend_time(t_philosopher *p, long ms)
{
	struct timeval	now;
	long			start_us;
	long			target_us;
	long			remaining_us;

	if (!is_enough_time(p, ms))
		return ;
	if (gettimeofday(&now, NULL) != 0)
		return ;
	start_us = now.tv_sec * 1000000L + now.tv_usec;
	target_us = start_us + (long)ms * 1000L;
	while (1)
	{
		if (gettimeofday(&now, NULL) != 0)
			return ;
		remaining_us = get_remaining(now, target_us);
		if (remaining_us <= 0)
			break ;
		usleep(get_chunk(remaining_us));
	}
}

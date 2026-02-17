/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 20:30:23 by emercier          #+#    #+#             */
/*   Updated: 2026/02/17 22:29:35 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	start_philos_threads(t_monitor *m)
{
	size_t	i;
	int		ret;

	i = 0;
	while (i < (size_t)m->params.number_of_philosophers)
	{
		ret = pthread_create(&m->philos[i].thread_id,
				NULL, (t_pthread_cb)philosopher_routine, &m->philos[i]);
		if (ret != 0)
		{
			set_prop(&m->should_stop, true);
			return (false);
		}
		i++;
	}
	return (true);
}

static bool	init_start_time(t_monitor *m)
{
	size_t	i;
	long	start_ms;

	start_ms = now_ms();
	if (start_ms < 0)
		return (false);
	m->start_ms = start_ms;
	i = 0;
	while (i < (size_t)m->params.number_of_philosophers)
	{
		m->philos[i].start_ms = start_ms;
		m->philos[i].last_meal.val = start_ms;
		i++;
	}
	return (true);
}

static void	join_philos_threads(t_monitor *m)
{
	size_t	i;

	i = 0;
	while (i < (size_t)m->params.number_of_philosophers)
	{
		pthread_join(m->philos[i].thread_id, NULL);
		i++;
	}
}

bool	run_simulation(t_monitor *m)
{
	pthread_t	monitor_thread_id;

	if (!start_philos_threads(m))
		return (false);
	if (pthread_create(
			&monitor_thread_id,
			NULL,
			(t_pthread_cb)monitor_routine,
			m) != 0)
	{
		set_prop(&m->should_stop, true);
		return (false);
	}
	if (!init_start_time(m))
		return (false);
	set_prop(&m->can_start, true);
	pthread_join(monitor_thread_id, NULL);
	join_philos_threads(m);
	return (true);
}

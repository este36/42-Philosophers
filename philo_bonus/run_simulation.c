/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 20:30:23 by emercier          #+#    #+#             */
/*   Updated: 2026/02/25 22:15:12 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	start_philos_threads(t_monitor *m, size_t *created)
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
			*created = i;
			return (false);
		}
		i++;
	}
	*created = i;
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
		set_prop(&m->philos[i].last_meal, start_ms);
		i++;
	}
	return (true);
}

static bool	philos_threads_abort(t_monitor *m, size_t count)
{
	size_t	i;

	i = 0;
	set_prop(&m->should_stop, true);
	while (i < count)
	{
		pthread_join(m->philos[i].thread_id, NULL);
		i++;
	}
	return (false);
}

static void	join_philos_threads(t_monitor *m)
{
	const size_t	n = m->params.number_of_philosophers;
	size_t			i;

	i = 0;
	while (i < n)
	{
		pthread_join(m->philos[i].thread_id, NULL);
		i++;
	}
}

bool	run_simulation(t_monitor *m)
{
	pthread_t	monitor_thread_id;
	size_t		created;

	created = 0;
	if (!start_philos_threads(m, &created))
		return (philos_threads_abort(m, created));
	if (pthread_create(
			&monitor_thread_id,
			NULL,
			(t_pthread_cb)monitor_routine,
			m) != 0)
		return (philos_threads_abort(m, created));
	if (!init_start_time(m))
	{
		philos_threads_abort(m, created);
		pthread_join(monitor_thread_id, NULL);
		return (false);
	}
	set_prop(&m->can_start, true);
	pthread_join(monitor_thread_id, NULL);
	join_philos_threads(m);
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 20:30:23 by emercier          #+#    #+#             */
/*   Updated: 2026/02/12 21:21:13 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	init_mutexes(t_monitor *m)
{
	const size_t	n = m->params.number_of_philosophers;
	size_t			i;

	if (pthread_mutex_init(m->cout, NULL) != 0
		|| pthread_mutex_init(&m->should_stop.mtx, NULL) != 0)
		return (false);
	i = 0;
	while (i < n)
	{
		if (pthread_mutex_init(&m->philos[i].right_fork, NULL) != 0
			|| pthread_mutex_init(&m->philos[i].state.mtx, NULL) != 0
			|| pthread_mutex_init(&m->philos[i].can_eat.mtx, NULL) != 0
			|| pthread_mutex_init(&m->philos[i].eat_times.mtx, NULL) != 0
			|| pthread_mutex_init(&m->philos[i].last_meal.mtx, NULL) != 0)
			return (false);
		i++;
	}
	return (true);
}

static void	init_philos(t_philosopher *philos, t_philo_params params)
{
	const size_t	n = params.number_of_philosophers;
	size_t			i;

	if (n != 1)
	{
		philos[0].left_fork = &philos[n - 1].right_fork;
	}
	i = 0;
	while (i < n)
	{
		philos[i].id = i + 1;
		philos[i].params = params;
		if (i + 1 < n)
			philos[i + 1].left_fork = &philos[i].right_fork;
		i++;
	}
}

bool	run_simulation(t_philo_params params)
{
	t_monitor		monitor;
	t_philosopher	*philos;

	memset(&monitor, 0, sizeof(monitor));
	monitor.params = params;
	philos = malloc(sizeof(t_philosopher) * params.number_of_philosophers);
	if (philos == NULL)
		return (false);
	memset(&philos, 0, sizeof(t_philosopher) * params.number_of_philosophers);
	monitor.philos = philos;
	if (!init_mutexes(&monitor))
		return (false);
	init_philos(monitor.philos, params);
	return (true);
}

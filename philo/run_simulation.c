/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 20:30:23 by emercier          #+#    #+#             */
/*   Updated: 2026/02/12 22:04:32 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	destroy_philo_mutexes(t_philosopher *p, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		pthread_mutex_destroy(&p[i].right_fork);
		pthread_mutex_destroy(&p[i].state.mtx);
		pthread_mutex_destroy(&p[i].can_eat.mtx);
		pthread_mutex_destroy(&p[i].eat_times.mtx);
		pthread_mutex_destroy(&p[i].last_meal.mtx);
		i++;
	}
}

static bool	init_philo_mutexes(t_philosopher *philo)
{
	size_t					i;
	const pthread_mutex_t	*mutexes[5] = {
		&philo->right_fork, &philo->state.mtx,
		&philo->can_eat.mtx, &philo->eat_times.mtx,
		&philo->last_meal.mtx,
	};

	i = 0;
	while (i < 5)
	{
		if (pthread_mutex_init((pthread_mutex_t *)mutexes[i], NULL) != 0)
		{
			i--;
			while (i > 0)
			{
				pthread_mutex_destroy((pthread_mutex_t *)mutexes[i]);
				i--;
			}
			return (false);
		}
		i++;
	}
	return (true);
}

static bool	init_mutexes(t_monitor *m)
{
	const size_t	n = m->params.number_of_philosophers;
	size_t			i;

	if (pthread_mutex_init(&m->cout, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&m->should_stop.mtx, NULL) != 0)
	{
		pthread_mutex_destroy(&m->cout);
		return (false);
	}
	i = 0;
	while (i < n)
	{
		if (!init_philo_mutexes(&m->philos[i]))
		{
			destroy_philo_mutexes(m->philos, i);
			pthread_mutex_destroy(&m->cout);
			pthread_mutex_destroy(&m->should_stop.mtx);
			return (false);
		}
		i++;
	}
	return (true);
}

static void	init_philos(t_monitor *m)
{
	const size_t	n = m->params.number_of_philosophers;
	size_t			i;

	if (n != 1)
	{
		m->philos[0].left_fork = &m->philos[n - 1].right_fork;
	}
	i = 0;
	while (i < n)
	{
		m->philos[i].id = i + 1;
		m->philos[i].params = m->params;
		m->philos[i].cout = &m->cout;
		m->philos[i].should_stop = &m->should_stop;
		if (i + 1 < n)
			m->philos[i + 1].left_fork = &m->philos[i].right_fork;
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
	memset(philos, 0, sizeof(t_philosopher) * params.number_of_philosophers);
	monitor.philos = philos;
	if (!init_mutexes(&monitor))
		return (false);
	init_philos(&monitor);
	return (true);
}

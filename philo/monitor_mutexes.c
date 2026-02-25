/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_mutexes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:26:15 by emercier          #+#    #+#             */
/*   Updated: 2026/02/25 20:50:29 by emercier         ###   ########.fr       */
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
		pthread_mutex_destroy(&p[i].meal_count.mtx);
		pthread_mutex_destroy(&p[i].last_meal.mtx);
		i++;
	}
}

static bool	init_philo_mutexes(t_philosopher *philo)
{
	size_t					i;
	const pthread_mutex_t	*mutexes[5] = {
		&philo->right_fork, &philo->state.mtx,
		&philo->can_eat.mtx, &philo->meal_count.mtx,
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

void	monitor_destroy_mutexes(t_monitor *m, size_t philos_count)
{
	if (m->philos != NULL)
		destroy_philo_mutexes(m->philos, philos_count);
	pthread_mutex_destroy(&m->cout);
	pthread_mutex_destroy(&m->should_stop.mtx);
	pthread_mutex_destroy(&m->can_start.mtx);
}

bool	monitor_create_mutexes(t_monitor *m)
{
	const size_t	n = m->params.number_of_philosophers;
	size_t			i;

	if (pthread_mutex_init(&m->cout, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&m->should_stop.mtx, NULL) != 0)
		return (pthread_mutex_destroy(&m->cout), false);
	if (pthread_mutex_init(&m->can_start.mtx, NULL) != 0)
	{
		pthread_mutex_destroy(&m->should_stop.mtx);
		return (pthread_mutex_destroy(&m->cout), false);
	}
	i = 0;
	while (i < n)
	{
		if (!init_philo_mutexes(&m->philos[i]))
			return (monitor_destroy_mutexes(m, i), false);
		i++;
	}
	return (true);
}

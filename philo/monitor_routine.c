/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 21:52:22 by emercier          #+#    #+#             */
/*   Updated: 2026/02/25 20:47:57 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	philo_can_eat(t_monitor *m, size_t philo_index)
{
	t_philosopher	*left_philo;
	t_philosopher	*right_philo;

	if (m->params.number_of_philosophers == 1)
		return (false);
	if (philo_index == 0)
		left_philo = &m->philos[m->params.number_of_philosophers - 1];
	else
		left_philo = &m->philos[philo_index - 1];
	if (philo_index == (size_t)m->params.number_of_philosophers - 1)
		right_philo = &m->philos[0];
	else
		right_philo = &m->philos[philo_index + 1];
	if (get_prop(&left_philo->state) == STATE_EATING
		|| get_prop(&right_philo->state) == STATE_EATING)
		return (false);
	return (true);
}

static void	manage_meal(t_monitor *m, size_t philo_index)
{
	if (get_prop(&m->philos[philo_index].state) == STATE_THINKING
		&& philo_can_eat(m, philo_index))
	{
		set_prop(&m->philos[philo_index].can_eat, true);
	}
}

static bool	monitor_loop_default(t_monitor *m)
{
	size_t	i;

	i = 0;
	while (i < (size_t)m->params.number_of_philosophers)
	{
		if (get_prop(&m->philos[i].state) == STATE_DEAD)
		{
			set_prop(&m->should_stop, true);
			philo_log(&m->philos[i], LOG_DIED);
			return (true);
		}
		manage_meal(m, i);
		i++;
	}
	return (false);
}

static bool	monitor_loop_optional(t_monitor *m)
{
	int	n_out;
	int	i;

	i = 0;
	n_out = 0;
	while (i < m->params.number_of_philosophers)
	{
		if (get_prop(&m->philos[i].state) == STATE_DEAD)
		{
			if (!m->deaths[i])
			{
				philo_log(&m->philos[i], LOG_DIED);
				m->deaths[i] = true;
			}
			n_out++;
		}
		else if (get_prop(&m->philos[i].meal_count) >= m->params.times_must_eat)
			n_out++;
		manage_meal(m, i);
		i++;
	}
	return (n_out == m->params.number_of_philosophers);
}

void	*monitor_routine(t_monitor *m)
{
	t_monitor_loop	monitor_loop;

	if (m->params.times_must_eat)
		monitor_loop = monitor_loop_optional;
	else
		monitor_loop = monitor_loop_default;
	while (!get_prop(&m->can_start))
		usleep(15);
	while (true)
	{
		if (monitor_loop(m))
			break ;
		usleep(2);
	}
	set_prop(&m->should_stop, true);
	return (NULL);
}

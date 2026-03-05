/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 21:52:22 by emercier          #+#    #+#             */
/*   Updated: 2026/03/05 17:00:22 by emercier         ###   ########.fr       */
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

static bool	manage_meal(t_monitor *m, size_t philo_index)
{
	if (get_prop(&m->philos[philo_index].state) == STATE_THINKING
		&& philo_can_eat(m, philo_index))
	{
		set_prop(&m->philos[philo_index].can_eat, true);
		while (get_prop(&m->philos[philo_index].state) != STATE_EATING)
		{
			if (philo_is_dead(&m->philos[philo_index]))
			{
				set_prop(&m->should_stop, true);
				philo_log(&m->philos[philo_index], LOG_DIED);
				return (false);
			}
			usleep(2);
		}
	}
	return (true);
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
			return (false);
		}
		if (!manage_meal(m, i))
			return (false);
		i++;
	}
	return (true);
}

static bool	monitor_loop_optional(t_monitor *m)
{
	int	meal_goals_complete;
	int	i;

	i = 0;
	meal_goals_complete = 0;
	while (i < m->params.number_of_philosophers)
	{
		if (get_prop(&m->philos[i].state) == STATE_DEAD)
		{
			set_prop(&m->should_stop, true);
			philo_log(&m->philos[i], LOG_DIED);
			return (false);
		}
		if (get_prop(&m->philos[i].meal_count) >= m->params.times_must_eat)
			meal_goals_complete++;
		if (!manage_meal(m, i))
			return (false);
		i++;
	}
	return (meal_goals_complete != m->params.number_of_philosophers);
}

void	*monitor_routine(t_monitor *m)
{
	t_monitor_loop	monitor_loop;

	if (m->params.times_must_eat)
		monitor_loop = monitor_loop_optional;
	else
		monitor_loop = monitor_loop_default;
	wait_prop(&m->should_stop, &m->can_start, true);
	while (true)
	{
		if (!monitor_loop(m))
			break ;
	}
	set_prop(&m->should_stop, true);
	return (NULL);
}

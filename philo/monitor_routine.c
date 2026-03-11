/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                   :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 21:52:22 by emercier          #+#    #+#             */
/*   Updated: 2026/03/11 16:05:04 by emercier       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	monitor_philo_eat(t_monitor *m, t_philosopher *p)
{
	set_prop(&p->can_eat, true);
	while (get_prop(&p->state) != STATE_EATING)
	{
		if (philo_is_dead(p))
		{
			set_prop(&m->should_stop, true);
			philo_log(p, LOG_DIED);
			return (false);
		}
		usleep(2);
	}
	return (true);
}

static bool	manage_meal(t_monitor *m, t_philosopher *p)
{
	int	choice_index;

	if (m->choices_count == 0)
		choice_index = 0;
	else
		choice_index = m->choices_count - 1;
	if (get_prop(&p->state) == STATE_THINKING
		&& philo_can_eat(m, p))
	{
		m->choices[choice_index] = p;
		m->choices_count++;
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
		if (!manage_meal(m, &m->philos[i]))
			return (false);
		i++;
	}
	return (monitor_choose(m));
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
		if (!manage_meal(m, &m->philos[i]))
			return (false);
		i++;
	}
	return (
		monitor_choose(m)
		&& meal_goals_complete != m->params.number_of_philosophers);
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
		m->choices_count = 0;
	}
	set_prop(&m->should_stop, true);
	return (NULL);
}

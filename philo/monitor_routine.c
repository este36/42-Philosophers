/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 21:52:22 by emercier          #+#    #+#             */
/*   Updated: 2026/03/13 17:31:42 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	monitor_philo_eat(t_monitor *m, t_philosopher *p)
{
	if (!philo_can_eat(m, p))
		return (true);
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
	pthread_mutex_lock(&m->cout);
	log_debug("DONE\n");
	pthread_mutex_unlock(&m->cout);
	return (true);
}

static void	manage_meal(t_monitor *m, t_philosopher *p)
{
	size_t	i;

	if (get_prop(&p->state) == STATE_THINKING)
	{
		i = 0;
		while (i < m->choices_count)
		{
			if (m->choices[i]->id == p->id)
				return ;
			i++;
		}
		m->choices[m->choices_count++] = p;
	}
	return ;
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
		manage_meal(m, &m->philos[i]);
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
		manage_meal(m, &m->philos[i]);
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
	usleep(300);
	while (true)
	{
		if (!monitor_loop(m))
			break ;
	}
	set_prop(&m->should_stop, true);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 21:48:25 by emercier          #+#    #+#             */
/*   Updated: 2026/03/08 19:56:11 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	philo_is_dead(t_philosopher *p)
{
	long	state;

	state = get_prop(&p->state);
	if (state == STATE_DEAD)
		return (true);
	if (state == STATE_EATING)
		return (false);
	if (now_ms() - get_prop(&p->last_meal) >= p->params.time_to_die)
	{
		set_prop(&p->state, STATE_DEAD);
		return (true);
	}
	return (false);
}

static bool	think_routine(t_philosopher *p)
{
	set_prop(&p->state, STATE_THINKING);
	philo_log(p, LOG_THINKING);
	while (
		!get_prop(&p->can_eat)
		&& !get_prop(p->should_stop)
		&& !philo_is_dead(p))
	{
		usleep(30);
	}
	set_prop(&p->can_eat, false);
	return (!philo_is_dead(p));
}

static bool	eat_routine(t_philosopher *p)
{
	pthread_mutex_lock(p->left_fork);
	philo_log(p, LOG_FORK_TAKEN);
	pthread_mutex_lock(&p->right_fork);
	philo_log(p, LOG_FORK_TAKEN);
	set_prop(&p->last_meal, now_ms());
	set_prop(&p->state, STATE_EATING);
	philo_log(p, LOG_EATING);
	increment_prop(&p->meal_count);
	philo_spend_time(p, p->params.time_to_eat);
	pthread_mutex_unlock(p->left_fork);
	pthread_mutex_unlock(&p->right_fork);
	return (!philo_is_dead(p));
}

static bool	sleep_routine(t_philosopher *p)
{
	set_prop(&p->state, STATE_SLEEPING);
	philo_log(p, LOG_SLEEPING);
	philo_spend_time(p, p->params.time_to_sleep);
	return (!philo_is_dead(p));
}

void	*philosopher_routine(t_philosopher *p)
{
	wait_prop(p->should_stop, p->can_start, true);
	if (p->id % 2 == 0)
	{
		if (!sleep_routine(p))
			return (NULL);
	}
	while (!get_prop(p->should_stop))
	{
		if (!think_routine(p))
			break ;
		if (get_prop(p->should_stop))
			break ;
		if (p->left_fork)
		{
			if (!eat_routine(p))
				break ;
			if (get_prop(p->should_stop))
				break ;
			if (!sleep_routine(p))
				break ;
		}
	}
	return (NULL);
}

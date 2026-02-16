/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 21:48:25 by emercier          #+#    #+#             */
/*   Updated: 2026/02/16 22:53:31 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher_routine(t_philosopher *p)
{
	wait_prop(p->should_stop, p->can_start, true);
	while (!get_prop(p->should_stop))
	{
		set_prop(&p->state, STATE_THINKING);
		philo_log(p, LOG_THINKING);
		wait_prop(p->should_stop, &p->can_eat, true);
		set_prop(&p->can_eat, false);
		if (p->left_fork)
		{
			pthread_mutex_lock(p->left_fork);
			pthread_mutex_lock(&p->right_fork);
			set_prop(&p->state, STATE_EATING);
			philo_log(p, LOG_EATING);
			sleep_ms(p->params.time_to_eat);
			pthread_mutex_unlock(p->left_fork);
			pthread_mutex_unlock(&p->right_fork);
			set_prop(&p->state, STATE_SLEEPING);
			philo_log(p, LOG_SLEEPING);
			sleep_ms(p->params.time_to_sleep);
		}
	}
	return (NULL);
}

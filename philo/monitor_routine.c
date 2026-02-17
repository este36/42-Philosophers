/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 21:52:22 by emercier          #+#    #+#             */
/*   Updated: 2026/02/17 20:07:32 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	philo_can_eat(t_monitor *m, size_t philo_index)
{
	t_philosopher	*left_philo;

	if (m->params.number_of_philosophers == 1)
		return (false);
	if (philo_index == 0)
		left_philo = &m->philos[m->params.number_of_philosophers - 1];
	else
		left_philo = &m->philos[philo_index - 1];
	if (get_prop(&left_philo->state) == STATE_EATING)
		return (false);
	return (true);
}

static bool	still_alive(t_monitor *m)
{
	return (now_ms() - m->start_ms < 30000); // TODO: implement philos checks
}

void	*monitor_routine(t_monitor *m)
{
	size_t	i;

	while (!get_prop(&m->can_start))
		usleep(15);
	while (still_alive(m))
	{
		i = 0;
		while (i < (size_t)m->params.number_of_philosophers)
		{
			if (get_prop(&m->philos[i].state) == STATE_THINKING
				&& philo_can_eat(m, i))
			{
				set_prop(&m->philos[i].can_eat, true);
			}
			i++;
		}
		usleep(15);
	}
	set_prop(&m->should_stop, true);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 21:52:22 by emercier          #+#    #+#             */
/*   Updated: 2026/02/24 22:58:12 by emercier         ###   ########.fr       */
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

static bool	still_alive(t_monitor *m)
{
	int	n_of_deaths;
	int	i;

	i = 0;
	n_of_deaths = 0;
	while (i < m->params.number_of_philosophers)
	{
		if (get_prop(&m->philos[i].state) == STATE_DEAD)
		{
			set_prop(&m->should_stop, true);
			philo_log(&m->philos[i], LOG_DIED);
			n_of_deaths++;
			return (false);
		}
		i++;
	}
	return (n_of_deaths != m->params.number_of_philosophers);
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
			if (get_prop(&m->philos[i].state) == STATE_DEAD)
			{
				set_prop(&m->should_stop, true);
				philo_log(&m->philos[i], LOG_DIED);
				return (NULL);
			}
			if (get_prop(&m->philos[i].state) == STATE_THINKING
				&& philo_can_eat(m, i))
			{
				set_prop(&m->philos[i].can_eat, true);
			}
			i++;
		}
	}
	set_prop(&m->should_stop, true);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 12:37:51 by emercier          #+#    #+#             */
/*   Updated: 2026/03/13 17:28:16 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philosopher	*get_left_philo(t_monitor *m, size_t philo_index)
{
	t_philosopher	*res;

	if (philo_index == 0)
		res = &m->philos[m->params.number_of_philosophers - 1];
	else
		res = &m->philos[philo_index - 1];
	return (res);
}

t_philosopher	*get_right_philo(t_monitor *m, size_t philo_index)
{
	t_philosopher	*res;

	if (philo_index == (size_t)m->params.number_of_philosophers - 1)
		res = &m->philos[0];
	else
		res = &m->philos[philo_index + 1];
	return (res);
}

t_philosopher	*starvest_philo(t_monitor *m)
{
	t_philosopher	*starvest;
	size_t			i;

	i = 0;
	starvest = &m->philos[i];
	while (i < (size_t)m->params.number_of_philosophers)
	{
		if (get_prop(&m->philos[i].last_meal_end)
			< get_prop(&starvest->last_meal_end))
			starvest = &m->philos[i];
		i++;
	}
	return (starvest);
}

bool	philo_can_eat(t_monitor *m, t_philosopher *p)
{
	t_philosopher	*left_philo;
	t_philosopher	*right_philo;

	if (m->params.number_of_philosophers == 1)
		return (false);
	if (p == starvest_philo(m))
	{
		pthread_mutex_lock(p->cout);
		log_debug("philo %d is the starvest\n", p->id);
		pthread_mutex_unlock(p->cout);
		return (true);
	}
	left_philo = get_left_philo(m, p->id - 1);
	right_philo = get_right_philo(m, p->id - 1);
	if (get_prop(&left_philo->state) == STATE_EATING
		|| get_prop(&right_philo->state) == STATE_EATING)
		return (false);
	return (true);
}

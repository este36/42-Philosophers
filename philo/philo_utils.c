/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 21:25:37 by emercier          #+#    #+#             */
/*   Updated: 2026/03/13 21:25:47 by emercier         ###   ########.fr       */
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

bool	is_odd_thinking(t_monitor *m, t_philosopher *p)
{
	const long	now = now_ms();
	float		ratio;
	long		lme;
	bool		ret;

	ratio = 0.0;
	if (!m->first_odd_eat)
		ratio = 1.0;
	lme = now - get_prop(&p->last_meal_end);
	ratio += (float)lme / (float)p->params.time_to_eat;
	ret = (m->params.number_of_philosophers % 2 && ratio >= 2.0);
	if (ret && !m->first_odd_eat)
		m->first_odd_eat = true;
	return (ret);
}

bool	philo_can_eat(t_monitor *m, t_philosopher *p)
{
	t_philosopher	*left_philo;
	t_philosopher	*right_philo;

	if (m->params.number_of_philosophers == 1)
		return (false);
	if (is_odd_thinking(m, p))
		return (true);
	left_philo = get_left_philo(m, p->id - 1);
	right_philo = get_right_philo(m, p->id - 1);
	if (get_prop(&left_philo->state) == STATE_EATING
		|| get_prop(&right_philo->state) == STATE_EATING)
		return (false);
	return (true);
}

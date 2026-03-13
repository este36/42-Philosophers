/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_choose.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 12:55:55 by emercier          #+#    #+#             */
/*   Updated: 2026/03/13 18:24:16 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	remove_unordered(t_monitor *m, int philo_id)
{
	t_philosopher	*last;
	size_t			i;

	if (m->choices_count == 0)
		return ;
	i = 0;
	while (i < m->choices_count && m->choices[i]->id != philo_id)
		i++;
	if (i == m->choices_count)
		return ;
	if (m->choices_count > 1)
	{
		last = m->choices[m->choices_count - 1];
		m->choices[m->choices_count - 1] = m->choices[i];
		m->choices[i] = last;
	}
	m->choices_count--;
}

bool	choices_left(t_monitor *m)
{
	size_t	i;

	i = 0;
	if (m->choices_count == 0)
		return (false);
	if (m->choices_count == 1)
	{
		m->choices_count = 0;
		monitor_philo_eat(m, m->choices[0]);
		return (false);
	}
	while (i < m->choices_count)
	{
		if (philo_can_eat(m, m->choices[i]))
			return (true);
		i++;
	}
	return (false);
}

bool	monitor_choose(t_monitor *m)
{
	t_philosopher	*best;
	size_t			i;

	while (choices_left(m))
	{
		best = m->choices[0];
		i = 1;
		while (i < m->choices_count)
		{
			if (get_prop(&m->choices[i]->last_meal_end)
				< get_prop(&best->last_meal_end))
				best = m->choices[i];
			i++;
		}
		if (!monitor_philo_eat(m, best))
			return (false);
		remove_unordered(m, best->id);
	}
	return (!get_prop(&m->should_stop));
}

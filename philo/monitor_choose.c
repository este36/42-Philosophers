/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_choose.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 12:55:55 by emercier          #+#    #+#             */
/*   Updated: 2026/03/13 16:13:49 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_neighboor(t_monitor *m, int philo_id1, int philo_id2)
{
	return (
		(philo_id2 == m->params.number_of_philosophers && philo_id1 == 1)
		|| (philo_id1 == m->params.number_of_philosophers && philo_id2 == 1)
		|| (philo_id1 + 1 == philo_id2) || (philo_id2 + 1 == philo_id1)
	);
}

t_philosopher	*get_best_choice(t_monitor *m,
							size_t choice_index,
							size_t count)
{
	t_philosopher	*best;
	t_philosopher	*last;

	last = m->choices[choice_index + count - 1];
	if (!last)
		return (m->choices[choice_index]);
	if (choice_index == 0
		&& is_neighboor(m, m->choices[0]->id, last->id))
	{
		if (get_prop(&m->choices[0]->last_meal_end)
			> get_prop(&last->last_meal_end))
			best = last;
		else
			best = m->choices[0];
	}
	else
		best = m->choices[choice_index];
	while (choice_index < count)
	{
		if (get_prop(&m->choices[choice_index]->last_meal_end)
			< get_prop(&best->last_meal_end))
			best = m->choices[choice_index];
		choice_index++;
	}
	return (best);
}

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
	size_t			i;
	t_philosopher	*best;

	while (choices_left(m))
	{
		i = 0;
		debug_choices(m); // debug
		while (i < m->choices_count)
		{
			if (i == m->choices_count - 1
				|| !is_neighboor(m, m->choices[i]->id, m->choices[i + 1]->id))
			{
				best = get_best_choice(m, 0, i + 1);
				if (!monitor_philo_eat(m, best))
					return (false);
				remove_unordered(m, best->id);
				break ;
			}
			i++;
		}
	}
	return (!get_prop(&m->should_stop));
}

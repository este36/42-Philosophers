/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_choose.c                                    :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 12:55:55 by emercier          #+#    #+#             */
/*   Updated: 2026/03/11 14:26:31 by emercier       ########   odam.nl        */
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
	if (choice_index == 0
		&& is_neighboor(m, m->choices[0]->id, last->id))
	{
		if (get_prop(&m->choices[0]->last_meal) > get_prop(&last->last_meal))
			best = last;
		else
			best = m->choices[0];
	}
	else
		best = m->choices[choice_index];
	while (choice_index < count)
	{
		if (get_prop(&m->choices[choice_index]->last_meal)
			< get_prop(&best->last_meal))
			best = m->choices[choice_index];
		choice_index++;
	}
	return (best);
}

bool	monitor_choose(t_monitor *m)
{
	size_t	i;
	size_t	j;

	if (m->choices_count == 1)
		return (monitor_philo_eat(m, m->choices[0]));
	i = 0;
	while (i < m->choices_count)
	{
		j = i + 1;
		while (j < m->choices_count)
		{
			if (!is_neighboor(m, i + 1, j + 1))
			{
				if (!monitor_philo_eat(m, get_best_choice(m, i, j)))
					return (false);
			}
			j++;
		}
		i = j + 1;
	}
	return (true);
}

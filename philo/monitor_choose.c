/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   monitor_choose.c                                    :+:    :+:           */
/*                                                      +:+                   */
/*   By: emercier <emercier@student.42lausanne.ch>     +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/09 16:25:37 by emercier       #+#    #+#                */
/*   Updated: 2026/03/09 16:46:27 by emercier       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	monitor_choose(t_monitor *m)
{
	int				i;
	t_philosopher	*best;

	if (m->choices_count == 0)
		return ;
	i = 1;
	best = &m->choices[0];
	while (i < len)
	{
		if (m->choices[i].last_meal < best->last_meal)
			best = &m->choices[i];
		i++;
	}
}

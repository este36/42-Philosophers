/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:26:06 by emercier          #+#    #+#             */
/*   Updated: 2026/02/16 19:55:53 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor_init_philos(t_monitor *m)
{
	const size_t	n = m->params.number_of_philosophers;
	size_t			i;

	if (n != 1)
	{
		m->philos[0].left_fork = &m->philos[n - 1].right_fork;
	}
	i = 0;
	while (i < n)
	{
		m->philos[i].id = i + 1;
		m->philos[i].params = m->params;
		m->philos[i].cout = &m->cout;
		m->philos[i].should_stop = &m->should_stop;
		if (i + 1 < n)
			m->philos[i + 1].left_fork = &m->philos[i].right_fork;
		i++;
	}
}

static bool	_monitor_abort(t_monitor *m)
{
	free(m->philos);
	return (false);
}

bool	monitor_init(t_monitor *m, t_philo_params params)
{
	const size_t	n_philos = params.number_of_philosophers;
	t_philosopher	*philos;

	memset(m, 0, sizeof(*m));
	philos = ft_calloc(1, sizeof(t_philosopher) * n_philos);
	if (philos == NULL)
		return (false);
	m->philos = philos;
	if (!monitor_create_mutexes(m))
		return (_monitor_abort(m));
	monitor_init_philos(m);
	return (true);
}

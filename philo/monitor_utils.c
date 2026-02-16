/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 20:37:43 by emercier          #+#    #+#             */
/*   Updated: 2026/02/16 21:31:27 by emercier         ###   ########.fr       */
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
		m->philos[i].can_start = &m->can_start;
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
	m->params = params;
	philos = ft_calloc(1, sizeof(t_philosopher) * n_philos);
	if (philos == NULL)
		return (false);
	m->philos = philos;
	if (!monitor_create_mutexes(m))
		return (_monitor_abort(m));
	monitor_init_philos(m);
	return (true);
}

void	monitor_destroy(t_monitor *m)
{
	if (m == NULL)
		return ;
	if (m->philos != NULL)
	{
		monitor_destroy_mutexes(m);
		free(m->philos);
		m->philos = NULL;
	}
}

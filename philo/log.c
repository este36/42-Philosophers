/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:28:00 by emercier          #+#    #+#             */
/*   Updated: 2026/03/13 16:28:17 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <stdarg.h>
#include <fcntl.h>

void	philo_log(t_philosopher *philo, const char *msg)
{
	long	now;
	int		ms;

	if (get_prop(philo->should_stop) && ft_strcmp(msg, LOG_DIED) != 0)
		return ;
	now = now_ms();
	if (now < 0)
		return ;
	ms = (int)(now - philo->start_ms);
	pthread_mutex_lock(philo->cout);
	printf("%d %d %s\n", ms, philo->id, msg);
	log_debug("----		%d %d %s\n", ms, philo->id, msg);
	pthread_mutex_unlock(philo->cout);
}

void	debug_choices(t_monitor *m)
{
	size_t			i;
	long			now;
	t_philosopher	*p;

	now = now_ms();
	pthread_mutex_lock(&m->cout);
	log_debug("(%d) %d choice(s): [",
		(int)now - m->start_ms, m->choices_count);
	i = 0;
	while (i < m->choices_count)
	{
		p = m->choices[i];
		log_debug("{id: %d, last_meal_end: %d}",
			p->id, (int)now - (int)get_prop(&p->last_meal_end));
		if (i + 1 < m->choices_count)
			log_debug(", ");
		else
			log_debug("]\n");
		i++;
	}
	pthread_mutex_unlock(&m->cout);
}

void	log_debug(const char *format, ...)
{
	int			fd;
	va_list		lst;

	fd = open("result.txt", O_CREAT | O_APPEND | O_WRONLY, 0666);
	if (fd > 0)
	{
		va_start(lst, format);
		vdprintf(fd, format, lst);
		va_end(lst);
		close(fd);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 18:26:11 by emercier          #+#    #+#             */
/*   Updated: 2026/03/13 18:26:51 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <stdarg.h>
#include <fcntl.h>

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

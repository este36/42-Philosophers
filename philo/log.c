/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:28:00 by emercier          #+#    #+#             */
/*   Updated: 2026/03/13 15:52:49 by emercier         ###   ########.fr       */
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
	pthread_mutex_unlock(philo->cout);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                               :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:28:00 by emercier          #+#    #+#             */
/*   Updated: 2026/03/11 16:14:54 by emercier       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

#define LOG_FILE 
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
void	log_debug(const char *fmt, ...)
{
	va_list	arg_list;
	int fd = open("result.txt", O_CREAT | O_APPEND | O_WRONLY, 0777);
	va_start(arg_list, fmt);
	vdprintf(fd, fmt, arg_list);
	va_end(arg_list);
	close(fd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:28:00 by emercier          #+#    #+#             */
/*   Updated: 2026/03/13 18:26:47 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_log(t_philosopher *philo, const char *msg)
{
	long	now;
	int		ms;

	if (get_prop(philo->should_stop) && ft_strcmp(msg, LOG_DIED) != 0)
		return ;
	pthread_mutex_lock(philo->cout);
	now = now_ms();
	if (now < 0)
		return ;
	ms = (int)(now - philo->start_ms);
	printf("%d %d %s\n", ms, philo->id, msg);
	pthread_mutex_unlock(philo->cout);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:28:00 by emercier          #+#    #+#             */
/*   Updated: 2026/02/17 23:12:17 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_log(t_philosopher *philo, const char *msg)
{
	long	now;
	int		ms;

	now = now_ms();
	if (now < 0)
		return ;
	ms = (int)(now - philo->start_ms);
	pthread_mutex_lock(philo->cout);
	printf("%d %d %s\n", ms, philo->id, msg);
	pthread_mutex_unlock(philo->cout);
}

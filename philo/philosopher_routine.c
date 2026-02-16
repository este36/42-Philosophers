/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 21:48:25 by emercier          #+#    #+#             */
/*   Updated: 2026/02/16 21:59:02 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher_routine(t_philosopher *p)
{
	philo_log(p, "waiting to start...");
	while (!get_prop(p->can_start))
		usleep(15);
	philo_log(p, "eww");
	while (!get_prop(p->should_stop))
		sleep_ms(50);
	philo_log(p, "i'm dying");
	return (NULL);
}

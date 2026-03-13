/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prop_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 21:22:57 by emercier          #+#    #+#             */
/*   Updated: 2026/03/13 21:22:59 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_prop(t_prop *prop)
{
	long	val;

	pthread_mutex_lock(&prop->mtx);
	val = prop->val;
	pthread_mutex_unlock(&prop->mtx);
	return (val);
}

long	set_prop(t_prop *prop, long val)
{
	long	ret;

	pthread_mutex_lock(&prop->mtx);
	prop->val = val;
	ret = prop->val;
	pthread_mutex_unlock(&prop->mtx);
	return (ret);
}

void	wait_prop(t_prop *should_stop, t_prop *prop, long val)
{
	while (get_prop(prop) != val && !get_prop(should_stop))
		usleep(8);
}

void	increment_prop(t_prop *prop)
{
	pthread_mutex_lock(&prop->mtx);
	prop->val += 1;
	pthread_mutex_unlock(&prop->mtx);
}

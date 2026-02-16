/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prop_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 17:04:10 by emercier          #+#    #+#             */
/*   Updated: 2026/02/16 23:28:13 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_prop(t_prop *prop)
{
	int	val;

	pthread_mutex_lock(&prop->mtx);
	val = prop->val;
	pthread_mutex_unlock(&prop->mtx);
	return (val);
}

int	set_prop(t_prop *prop, int val)
{
	int	ret;

	pthread_mutex_lock(&prop->mtx);
	prop->val = val;
	ret = prop->val;
	pthread_mutex_unlock(&prop->mtx);
	return (ret);
}

void	wait_prop(t_prop *should_stop, t_prop *prop, int val)
{
	while (get_prop(prop) != val && !get_prop(should_stop))
		usleep(50);
}

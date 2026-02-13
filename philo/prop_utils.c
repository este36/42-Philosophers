/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prop_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 17:04:10 by emercier          #+#    #+#             */
/*   Updated: 2026/02/13 17:11:31 by emercier         ###   ########.fr       */
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

void	set_prop(t_prop *prop, int val)
{
	pthread_mutex_lock(&prop->mtx);
	prop->val = val;
	pthread_mutex_unlock(&prop->mtx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:28:00 by emercier          #+#    #+#             */
/*   Updated: 2026/01/22 16:43:58 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	philo_log(t_philosopher *philo, const char *msg)
{
	int	ms;

	ms = 0; // TODO
	pthread_mutex_lock(philo->cout);
	printf("%d %d %s\n", ms,  philo->id, msg);
	pthread_mutex_unlock(philo->cout);
}

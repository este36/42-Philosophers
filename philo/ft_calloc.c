/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:54:36 by emercier          #+#    #+#             */
/*   Updated: 2026/01/21 21:03:27 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	new_len;
	void	*new;

	new_len = size * nmemb;
	new = (void *)malloc(new_len);
	if (!new)
		return (NULL);
	ft_bzero((void *)new, new_len);
	return ((void *)new);
}

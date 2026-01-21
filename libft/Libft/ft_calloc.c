/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:54:36 by emercier          #+#    #+#             */
/*   Updated: 2025/10/02 15:28:53 by emercier         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

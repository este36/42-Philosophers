/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:54:39 by emercier          #+#    #+#             */
/*   Updated: 2025/10/02 15:28:49 by emercier         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n && (uintptr_t)p & 7)
	{
		*p++ = 0;
		n--;
	}
	while (n >= 8)
	{
		*((uint64_t *)p) = 0;
		p += 8;
		n -= 8;
	}
	while (n--)
		*p++ = 0;
	return ;
}

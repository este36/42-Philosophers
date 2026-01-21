/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:54:00 by emercier          #+#    #+#             */
/*   Updated: 2025/10/02 15:32:21 by emercier         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	uint64_t		val;

	val = (unsigned char)c;
	val |= val << 8;
	val |= val << 16;
	val |= val << 32;
	p = s;
	while (n && ((uintptr_t)p & 7))
	{
		*p++ = (unsigned char)c;
		n--;
	}
	while (n >= 8)
	{
		*((uint64_t *)p) = val;
		p += 8;
		n -= 8;
	}
	while (n--)
		*p++ = (unsigned char)c;
	return (s);
}

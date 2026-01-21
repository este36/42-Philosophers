/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:53:02 by emercier          #+#    #+#             */
/*   Updated: 2025/10/02 15:33:36 by emercier         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	char		*p;
	uint64_t	*w;

	p = (char *)s;
	while (*p && ((uintptr_t)p & 7))
		p++;
	w = (uint64_t *)p;
	while (1)
	{
		if (((*w) - 0x0101010101010101ULL) & ~(*w) & 0x8080808080808080ULL)
			break ;
		w++;
	}
	p = (char *)w;
	while (*p)
		p++;
	return (p - s);
}

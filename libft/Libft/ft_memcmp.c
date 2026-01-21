/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:54:13 by emercier          #+#    #+#             */
/*   Updated: 2025/10/02 15:32:08 by emercier         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1 = s1;
	const unsigned char	*p2 = s2;
	size_t				i;

	i = 0;
	while (i < n && (((uintptr_t)(p1 + i) & 7) || ((uintptr_t)(p2 + i) & 7)))
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	while (i + 8 <= n)
	{
		if (*(uint64_t *)(p1 + i) != *(uint64_t *)(p2 + i))
			break ;
		i += 8;
	}
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}

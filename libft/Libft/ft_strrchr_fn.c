/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_fn.c                                     :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:52:41 by emercier          #+#    #+#             */
/*   Updated: 2025/11/17 20:04:03 by emercier       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr_fn(const char *s, int (*fn)(int c))
{
	size_t	n;

	n = ft_strlen(s);
	if (n == 0)
		return (NULL);
	while (n--)
	{
		if (fn(s[n]))
			return ((char *)&s[n]);
	}
	return (NULL);
}

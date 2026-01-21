/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:52:41 by emercier          #+#    #+#             */
/*   Updated: 2025/10/02 15:33:53 by emercier         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	n;

	if ((unsigned char)c == 0)
		return ((char *)s + ft_strlen(s));
	n = ft_strlen(s);
	if (n == 0)
		return (NULL);
	while (n--)
	{
		if ((unsigned char)s[n] == (unsigned char)c)
			return ((char *)&s[n]);
	}
	return (NULL);
}

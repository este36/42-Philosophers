/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_fn.c                                      :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:53:36 by emercier          #+#    #+#             */
/*   Updated: 2025/11/17 19:52:55 by emercier       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_fn(const char *s, int (*fn)(int c))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (fn(s[i]))
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                        :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:52:49 by emercier          #+#    #+#             */
/*   Updated: 2025/11/28 18:02:42 by emercier       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	const size_t	len = ft_strlen(big);
	const size_t	little_len = ft_strlen(little);
	size_t			i;
	size_t			j;

	i = 0;
	if (little_len == 0)
		return ((char *)big);
	if (little_len > len)
		return (NULL);
	while (big[i] && i < len)
	{
		j = 0;
		while (j < little_len && (i + j) < len)
		{
			if (big[i + j] != little[j])
				break ;
			j++;
		}
		if (j == little_len)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const size_t	little_len = ft_strlen(little);
	size_t			i;
	size_t			j;

	i = 0;
	if (little_len == 0)
		return ((char *)big);
	if (len == 0 && little_len != 0)
		return (NULL);
	while (big[i] && i < len)
	{
		j = 0;
		while (j < little_len && (i + j) < len)
		{
			if (big[i + j] != little[j])
				break ;
			j++;
		}
		if (j == little_len)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

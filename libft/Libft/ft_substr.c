/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:52:20 by emercier          #+#    #+#             */
/*   Updated: 2025/10/02 15:28:35 by emercier         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*start_ptr;
	size_t	max_cpy_len;
	char	*res;

	if (start >= ft_strlen(s))
	{
		res = ft_calloc(1, 1);
		return (res);
	}
	start_ptr = (char *)&s[start];
	max_cpy_len = ft_strlen(start_ptr);
	if (max_cpy_len < len)
		len = max_cpy_len;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	ft_memcpy(res, start_ptr, len);
	res[len] = '\0';
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:53:33 by emercier          #+#    #+#             */
/*   Updated: 2025/10/02 15:33:12 by emercier         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	s_len;
	char	*res;

	s_len = ft_strlen(s);
	res = malloc(s_len + 1);
	if (!res)
		return (NULL);
	ft_memcpy(res, s, s_len);
	res[s_len] = '\0';
	return (res);
}

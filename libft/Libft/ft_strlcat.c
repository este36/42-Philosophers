/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:53:15 by emercier          #+#    #+#             */
/*   Updated: 2025/10/02 15:33:27 by emercier         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_safe_dst_len(char *dest, size_t size)
{
	size_t	dst_len;

	dst_len = 0;
	while (dst_len < size && dest[dst_len])
		dst_len++;
	return (dst_len);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dst_index;
	size_t	src_index;
	size_t	dst_len;
	size_t	src_len;

	dst_len = get_safe_dst_len(dest, size);
	src_len = ft_strlen(src);
	dst_index = dst_len;
	if (dst_len >= size)
		return (src_len + size);
	src_index = 0;
	while (src[src_index] && dst_index < (size - 1))
		dest[dst_index++] = src[src_index++];
	dest[dst_index] = '\0';
	return (dst_len + src_len);
}

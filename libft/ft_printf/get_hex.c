/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hex.c                                           :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:48:08 by emercier          #+#    #+#             */
/*   Updated: 2025/11/11 12:18:57 by emercier       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_spec.h"

static void	remove_leading_zeros(char *val_buf)
{
	int			zeros;
	uint64_t	val_len;

	zeros = 0;
	val_len = 0;
	while (val_buf[zeros] && val_buf[zeros] == '0')
		zeros++;
	if (zeros)
	{
		val_len = 16 - zeros;
		ft_memmove(val_buf, val_buf + zeros, val_len);
		val_buf[val_len] = '\0';
	}
}

static void	_get_hex(char *val_buf, uint64_t n, int uppercase)
{
	static const char	*hex_lower = "0123456789abcdef";
	static const char	*hex_upper = "0123456789ABCDEF";
	const char			*hex;
	int					i;

	if (uppercase)
		hex = hex_upper;
	else
		hex = hex_lower;
	i = 0;
	while (i < 16)
	{
		val_buf[i] = hex[(n >> (60 - i * 4)) & 0xF];
		i++;
	}
}

char	*get_hex(uint64_t n, int uppercase)
{
	char	*val_buf;

	if (n == 0)
	{
		return (ft_strdup("0"));
	}
	val_buf = ft_calloc(1, 17);
	if (!val_buf)
		return (NULL);
	_get_hex(val_buf, n, uppercase);
	remove_leading_zeros(val_buf);
	return (val_buf);
}

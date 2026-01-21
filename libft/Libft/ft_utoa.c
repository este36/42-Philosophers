/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:54:19 by emercier          #+#    #+#             */
/*   Updated: 2025/10/02 15:29:30 by emercier         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_number_len(unsigned int n)
{
	size_t	res;

	res = 0;
	while (n != 0)
	{
		n /= 10;
		res++;
	}
	return (res);
}

static void	_utoa(char *dest, unsigned int n, size_t char_count)
{
	ssize_t	i;

	i = char_count - 1;
	while (i >= 0)
	{
		dest[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	dest[char_count] = '\0';
}

char	*ft_utoa(unsigned int n)
{
	size_t	char_count;
	char	*res;

	if (n == 0)
		return (ft_strdup("0"));
	char_count = get_number_len(n);
	res = malloc(char_count + 1);
	if (!res)
		return (NULL);
	_utoa(res, n, char_count);
	return (res);
}

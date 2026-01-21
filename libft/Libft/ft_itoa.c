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

static size_t	get_number_len(int n)
{
	size_t	res;

	res = 0;
	if (n < 0)
		res++;
	while (n != 0)
	{
		n /= 10;
		res++;
	}
	return (res);
}

static void	_itoa(char *dest, int n, size_t char_count)
{
	bool	is_negative;
	ssize_t	i;

	is_negative = (n < 0);
	if (is_negative)
		n *= -1;
	i = char_count - 1;
	while (i >= 0 && !(is_negative && i == 0))
	{
		dest[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	if (is_negative)
		dest[0] = '-';
	dest[char_count] = '\0';
}

char	*ft_itoa(int n)
{
	size_t	char_count;
	char	*res;

	if (n == (int)0x80000000)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	char_count = get_number_len(n);
	res = malloc(char_count + 1);
	if (!res)
		return (NULL);
	_itoa(res, n, char_count);
	return (res);
}

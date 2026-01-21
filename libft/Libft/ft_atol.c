/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                           :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:51:33 by emercier          #+#    #+#             */
/*   Updated: 2025/11/11 18:40:28 by emercier       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *nptr)
{
	size_t	i;
	int		is_minus;
	long	num;

	i = 0;
	num = 0;
	is_minus = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-')
	{
		is_minus = 1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (ft_isdigit(nptr[i]))
	{
		num *= 10;
		num += nptr[i] - '0';
		i++;
	}
	if (is_minus)
		num = -num;
	return (num);
}

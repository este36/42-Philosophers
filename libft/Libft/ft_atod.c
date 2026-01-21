/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 13:37:04 by emercier          #+#    #+#             */
/*   Updated: 2026/01/04 15:01:35 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	_point(const char *nptr, double *res)
{
	double	factor;

	factor = 0.1;
	nptr++;
	while (ft_isdigit(*nptr))
	{
		(*res) += (double)(*nptr - '0')*factor;
		factor *= 0.1;
		nptr++;
	}
}

double	ft_atod(const char *nptr)
{
	double	res;
	int		sign;

	res = 0.0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		res = res * 10.0 + (*nptr - '0');
		nptr++;
	}
	if (*nptr == '.')
		_point(nptr, &res);
	return (res * sign);
}

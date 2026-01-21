/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:26:07 by emercier          #+#    #+#             */
/*   Updated: 2025/10/24 18:45:11 by emercier         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_spec.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

static bool	get_val_int(t_ft_printf_spec *spec)
{
	const int	n = *(int *)spec->user_data;

	if (n < 0)
	{
		spec->is_negative = true;
		if (n == INT_MIN)
			spec->val.buf = ft_strdup("2147483648");
		else
			spec->val.buf = ft_itoa(n * -1);
	}
	else
		spec->val.buf = ft_itoa(n);
	if (!spec->val.buf)
		return (false);
	spec->val.len = ft_strlen(spec->val.buf);
	return (true);
}

bool	get_prec_padding(t_ft_printf_spec *spec)
{
	if (!spec->precision
		|| spec->precision < spec->val.len + spec->is_negative)
		spec->prec_padding.len = 0;
	else
		spec->prec_padding.len = spec->precision - spec->val.len;
	spec->prec_padding.buf = ft_calloc(1, spec->prec_padding.len + 1);
	if (!spec->prec_padding.buf)
	{
		free(spec->val.buf);
		return (false);
	}
	if (spec->prec_padding.len != 0)
		ft_memset(spec->prec_padding.buf, '0', spec->prec_padding.len);
	return (true);
}

bool	merge_prec_padding(t_ft_printf_spec *spec)
{
	t_dstr	res;

	ft_bzero(&res, sizeof(t_dstr));
	if (ft_dstr_init(&res, spec->val.len + spec->prec_padding.len + 2))
	{
		free(spec->val.buf);
		free(spec->prec_padding.buf);
		return (false);
	}
	if (spec->is_negative)
		ft_dstrncat(&res, "-", 1);
	ft_dstrncat(&res, spec->prec_padding.buf, spec->prec_padding.len);
	ft_dstrncat(&res, spec->val.buf, spec->val.len);
	free(spec->val.buf);
	spec->val.buf = res.buf;
	spec->val.len = res.len;
	spec->is_negative = false;
	return (true);
}

bool	apply_precision_int(t_ft_printf_spec *spec)
{
	if (!get_val_int(spec))
		return (false);
	if (spec->flags & SPEC_FLAG_POINT)
	{
		if (!get_prec_padding(spec))
			return (false);
		if (!merge_prec_padding(spec))
			return (false);
		free(spec->prec_padding.buf);
	}
	return (true);
}

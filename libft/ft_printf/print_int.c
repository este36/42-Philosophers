/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:01:49 by emercier          #+#    #+#             */
/*   Updated: 2025/10/24 18:44:24 by emercier         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_ops.h"
#include "ft_printf_spec.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

static void	merge_padding(t_ft_printf_spec *spec, t_dstr *res)
{
	if (spec->is_negative && spec->flags & SPEC_FLAG_ZERO)
	{
		ft_dstrncat(res, "-", 1);
		if (spec->padding.len > 1)
			ft_dstrncat(res, spec->padding.buf + 1, spec->padding.len - 1);
		ft_dstrncat(res, spec->val.buf, spec->val.len);
	}
	else if (spec->flags & SPEC_FLAG_MINUS)
	{
		if (spec->is_negative)
			ft_dstrncat(res, "-", 1);
		ft_dstrncat(res, spec->val.buf, spec->val.len);
		ft_dstrncat(res, spec->padding.buf, spec->padding.len);
	}
	else
	{
		ft_dstrncat(res, spec->padding.buf, spec->padding.len);
		if (spec->is_negative)
			ft_dstrncat(res, "-", 1);
		ft_dstrncat(res, spec->val.buf, spec->val.len);
	}
}

bool	get_print_buf_int(t_ft_printf_spec *spec)
{
	t_dstr	res;

	ft_bzero(&res, sizeof(t_dstr));
	if (ft_dstr_init(&res, spec->padding.len + spec->val.len + 2) != 0)
	{
		free(spec->padding.buf);
		free(spec->val.buf);
		return (false);
	}
	if (!spec->is_negative && spec->flags & SPEC_FLAG_SPACE)
		ft_dstrputc(&res, ' ');
	else if (!spec->is_negative && spec->flags & SPEC_FLAG_PLUS)
		ft_dstrputc(&res, '+');
	merge_padding(spec, &res);
	spec->toprint.buf = res.buf;
	spec->toprint.len = res.len;
	return (true);
}

int	print_int(va_list *arg_list, t_ft_printf_spec *spec)
{
	const int	n = va_arg(*arg_list, int);

	spec->apply_precision = apply_precision_int;
	spec->get_print_buf = get_print_buf_int;
	spec->user_data = (int *)&n;
	return (print_padded(spec));
}

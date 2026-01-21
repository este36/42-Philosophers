/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                        :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:01:23 by emercier          #+#    #+#             */
/*   Updated: 2025/11/11 12:19:05 by emercier       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_spec.h"
#include "ft_printf_ops.h"

static bool	get_buffer_value(t_ft_printf_spec *spec)
{
	spec->val.buf = malloc(2);
	if (!spec->val.buf)
		return (false);
	spec->val.len = 1;
	spec->val.buf[0] = *(char *)spec->user_data;
	spec->val.buf[1] = '\0';
	return (true);
}

static bool	get_print_buffer(t_ft_printf_spec *spec)
{
	t_dstr	res;

	ft_bzero(&res, sizeof(t_dstr));
	if (ft_dstr_init(&res, spec->padding.len + 2) != 0)
	{
		free(spec->padding.buf);
		free(spec->val.buf);
		return (false);
	}
	if (spec->flags & SPEC_FLAG_MINUS)
	{
		ft_dstrputc(&res, spec->val.buf[0]);
		ft_dstrncat(&res, spec->padding.buf, spec->padding.len);
	}
	else
	{
		ft_dstrncat(&res, spec->padding.buf, spec->padding.len);
		ft_dstrputc(&res, spec->val.buf[0]);
	}
	spec->toprint.buf = res.buf;
	spec->toprint.len = res.len;
	return (true);
}

int	print_char(va_list *arg_list, t_ft_printf_spec *spec)
{
	const int	val = va_arg(*arg_list, int );

	spec->apply_precision = get_buffer_value;
	spec->get_print_buf = get_print_buffer;
	spec->user_data = (char *)&val;
	return (print_padded(spec));
}

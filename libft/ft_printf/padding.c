/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                           :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:49:47 by emercier          #+#    #+#             */
/*   Updated: 2025/11/17 20:29:34 by emercier       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_spec.h"
#include "ft_printf_spec.h"
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

static bool	apply_precision(t_ft_printf_spec *spec)
{
	spec->val.buf = ft_strdup((char *)spec->user_data);
	if (!spec->val.buf)
		return (false);
	spec->val.len = ft_strlen(spec->val.buf);
	if (spec->flags & SPEC_FLAG_POINT && spec->precision < spec->val.len)
	{
		if (spec->val.len != 0)
		{
			spec->val.len = spec->precision;
			spec->val.buf[spec->val.len] = '\0';
		}
	}
	return (true);
}

static bool	get_padding(t_ft_printf_spec *spec)
{
	if (!spec->min_width || spec->min_width < spec->val.len)
		spec->padding.len = 0;
	else
	{
		spec->padding.len = spec->min_width - spec->val.len;
		if (spec->padding.len && !(spec->flags & SPEC_FLAG_ZERO))
			spec->padding.len -= spec->is_negative;
	}
	spec->padding.buf = ft_calloc(1, spec->padding.len + 1);
	if (!spec->padding.buf)
	{
		free(spec->val.buf);
		return (false);
	}
	if (spec->min_width)
	{
		if (spec->flags & SPEC_FLAG_ZERO)
			ft_memset(spec->padding.buf, '0', spec->padding.len);
		else
			ft_memset(spec->padding.buf, ' ', spec->padding.len);
	}
	return (true);
}

static bool	get_print_buf(t_ft_printf_spec *spec)
{
	if (spec->flags & SPEC_FLAG_MINUS)
		spec->toprint.buf = ft_strjoin(spec->val.buf, spec->padding.buf);
	else
		spec->toprint.buf = ft_strjoin(spec->padding.buf, spec->val.buf);
	if (!spec->toprint.buf)
	{
		free(spec->val.buf);
		free(spec->padding.buf);
		return (false);
	}
	spec->toprint.len = ft_strlen(spec->toprint.buf);
	return (true);
}

int	print_padded(t_ft_printf_spec *spec)
{
	int			printed;

	if (spec->apply_precision == NULL)
		spec->apply_precision = apply_precision;
	if (!spec->apply_precision(spec))
		return (-1);
	if (!get_padding(spec))
		return (-1);
	if (spec->get_print_buf == NULL)
		spec->get_print_buf = get_print_buf;
	if (!spec->get_print_buf(spec))
		return (-1);
	if (spec->write_cb == NULL)
		spec->write_cb = write_stdout;
	printed = spec->write_cb(spec);
	free(spec->toprint.buf);
	free(spec->padding.buf);
	free(spec->val.buf);
	return (printed);
}

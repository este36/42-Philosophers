/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:01:52 by emercier          #+#    #+#             */
/*   Updated: 2025/10/24 17:00:15 by emercier         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_ops.h"
#include "ft_printf_spec.h"

static bool	get_val_hex_upper(t_ft_printf_spec *spec)
{
	char	*hex_str;

	hex_str = get_hex(*(unsigned int *)spec->user_data, HEX_UPPERCASE);
	if (!hex_str)
		return (false);
	if (spec->flags & SPEC_FLAG_SHARP && hex_str[0] != '0')
	{
		spec->val.buf = ft_strjoin("0X", hex_str);
		if (!spec->val.buf)
			return (false);
		free(hex_str);
	}
	else
		spec->val.buf = hex_str;
	spec->val.len = ft_strlen(spec->val.buf);
	return (true);
}

static bool	apply_precision_hex_upper(t_ft_printf_spec *spec)
{
	if (!get_val_hex_upper(spec))
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

int	print_hex_upper(va_list *arg_list, t_ft_printf_spec *spec)
{
	const unsigned int	val = (unsigned int)va_arg(*arg_list, unsigned int);

	spec->apply_precision = apply_precision_hex_upper;
	spec->get_print_buf = get_print_buf_int;
	spec->user_data = (unsigned int *)&val;
	return (print_padded(spec));
}

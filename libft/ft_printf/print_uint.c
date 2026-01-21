/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:01:30 by emercier          #+#    #+#             */
/*   Updated: 2025/10/24 16:55:16 by emercier         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_ops.h"
#include "ft_printf_spec.h"

bool	get_val_uint(t_ft_printf_spec *spec)
{
	spec->val.buf = ft_utoa(*(unsigned int *)spec->user_data);
	if (!spec->val.buf)
		return (false);
	spec->val.len = ft_strlen(spec->val.buf);
	return (true);
}

bool	apply_precision_uint(t_ft_printf_spec *spec)
{
	if (!get_val_uint(spec))
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

int	print_uint(va_list *arg_list, t_ft_printf_spec *spec)
{
	const unsigned int	val = va_arg(*arg_list, unsigned int);

	spec->apply_precision = apply_precision_uint;
	spec->get_print_buf = get_print_buf_int;
	spec->user_data = (unsigned int *)&val;
	return (print_padded(spec));
}

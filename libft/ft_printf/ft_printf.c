/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                         :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 20:32:23 by emercier          #+#    #+#             */
/*   Updated: 2025/11/17 22:53:51 by emercier       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_spec.h"
#include "ft_printf_ops.h"
#include <limits.h>

bool	lookup(va_list *arg_list, t_ft_printf_spec *spec, int *print_count)
{
	static const t_ft_printf_op	ops[14] = {
		print_ptr, print_char,
		print_int, print_str,
		print_hex_upper, print_uint,
		NULL, print_int,
		print_hex_lower, print_percent,
		NULL, NULL, NULL, NULL
	};
	const t_ft_printf_op		op = ops[spec->conversion % 14];
	int							printed;

	if (!op)
		return (0);
	printed = op(arg_list, spec);
	if (printed < 0)
		return (false);
	*print_count += printed;
	return (true);
}

int	print_safe_raw_bytes(
					const char **fmt,
					int *print_count,
					t_write_op write_op,
					void *user_out)
{
	const char	*next_percent = ft_strchr(*fmt, '%');
	int			printed;

	if (!next_percent)
		printed = ft_strlen(*fmt);
	else
		printed = (next_percent - *fmt);
	if (write_raw(write_op, user_out, *fmt, printed) < 0)
		return (false);
	*fmt += printed;
	*print_count += printed;
	return (true);
}

int	cleanup_and_fail(va_list *arg_list)
{
	va_end(*arg_list);
	return (-1);
}

int	ft_printf_fn(
		t_write_op write_op, void *user_out,
		const char *fmt, va_list *arg_list)
{
	int					print_count;
	t_ft_printf_spec	spec;

	print_count = 0;
	while (*fmt)
	{
		if (!print_safe_raw_bytes(&fmt, &print_count, write_op, user_out))
			return (cleanup_and_fail(arg_list));
		if (*fmt)
		{
			fmt++;
			parse_spec(&spec, &fmt, arg_list);
			spec.user_write_output = user_out;
			spec.write_cb = write_op;
			if (!lookup(arg_list, &spec, &print_count))
				return (cleanup_and_fail(arg_list));
		}
	}
	return (print_count);
}

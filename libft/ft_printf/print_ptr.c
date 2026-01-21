/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:01:37 by emercier          #+#    #+#             */
/*   Updated: 2025/10/24 01:00:59 by emercier         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_ops.h"
#include "ft_printf_spec.h"

int	print_ptr(va_list *arg_list, t_ft_printf_spec *spec)
{
	const uintptr_t	val = (uintptr_t)va_arg(*arg_list, void *);
	char			*hex_buf;
	char			*val_buf;
	uint32_t		printed;

	if (!val)
		hex_buf = ft_strdup("(nil)");
	else
		hex_buf = get_hex((uint64_t)val, HEX_LOWERCASE);
	if (!hex_buf)
		return (0);
	if (!val)
		val_buf = ft_strdup(hex_buf);
	else
		val_buf = ft_strjoin("0x", hex_buf);
	free(hex_buf);
	if (!val_buf)
		return (0);
	spec->user_data = val_buf;
	printed = print_padded(spec);
	free(val_buf);
	return (printed);
}

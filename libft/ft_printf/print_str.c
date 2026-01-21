/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:01:33 by emercier          #+#    #+#             */
/*   Updated: 2025/10/24 16:36:10 by emercier         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_ops.h"
#include "ft_printf_spec.h"
#include "ft_printf_spec.h"

int	print_str(va_list *arg_list, t_ft_printf_spec *spec)
{
	const char	*val_buf = va_arg(*arg_list, char *);
	const char	*null_str = "(null)";
	const char	*empty_str = "";

	if (!val_buf)
	{
		if (spec->flags & SPEC_FLAG_POINT && spec->precision <= 5)
			spec->user_data = (char *)empty_str;
		else
			spec->user_data = (char *)null_str;
	}
	else
		spec->user_data = (char *)val_buf;
	return (print_padded(spec));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_printf_ops.c                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: emercier <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/11/17 20:45:23 by emercier       #+#    #+#                */
/*   Updated: 2025/11/17 21:36:13 by emercier       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_spec.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	arg_list;
	int		printed;

	va_start(arg_list, fmt);
	printed = ft_printf_fn(NULL, NULL, fmt, &arg_list);
	va_end(arg_list);
	return (printed);
}

int	ft_dprintf(int fd, const char *fmt, ...)
{
	va_list	arg_list;
	int		printed;

	va_start(arg_list, fmt);
	printed = ft_printf_fn(write_fd, &fd, fmt, &arg_list);
	va_end(arg_list);
	return (printed);
}

int	ft_snprintf(char *str, size_t size, const char *fmt, ...)
{
	va_list	arg_list;
	int		printed;
	t_dstr	dest;

	ft_bzero(&dest, sizeof(t_dstr));
	dest.cap = size;
	dest.buf = str;
	va_start(arg_list, fmt);
	printed = ft_printf_fn(write_str, &dest, fmt, &arg_list);
	va_end(arg_list);
	return (printed);
}

int	ft_dsprintf(t_dstr *dstr, const char *fmt, ...)
{
	va_list	arg_list;
	int		printed;

	va_start(arg_list, fmt);
	printed = ft_printf_fn(write_dstr, dstr, fmt, &arg_list);
	va_end(arg_list);
	return (printed);
}

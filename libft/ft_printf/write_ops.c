/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   write_ops.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: emercier <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/11/17 20:16:01 by emercier       #+#    #+#                */
/*   Updated: 2025/11/17 22:55:06 by emercier       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_spec.h"

int	write_stdout(t_ft_printf_spec *spec)
{
	return (write(1, spec->toprint.buf, spec->toprint.len));
}

int	write_fd(t_ft_printf_spec *spec)
{
	const int	fd = *(int*)spec->user_write_output;

	return (write(fd, spec->toprint.buf, spec->toprint.len));
}

int	write_str(t_ft_printf_spec *spec)
{
	t_dstr	*dst;
	size_t	toprint_len;

	dst = (t_dstr *)spec->user_write_output;
	if (dst->len + spec->toprint.len >= dst->cap)
		toprint_len = dst->cap - dst->len;
	else
		toprint_len = spec->toprint.len;
	if (ft_dstrncat(dst, spec->toprint.buf, toprint_len) != 0)
		return (-1);
	return (toprint_len);
}

int	write_dstr(t_ft_printf_spec *spec)
{
	t_dstr	*dst;

	dst = (t_dstr *)spec->user_write_output;
	if (ft_dstrncat(dst, spec->toprint.buf, spec->toprint.len) != 0)
		return (-1);
	return (spec->toprint.len);
}

int	write_raw(
		t_write_op write_op,
		void *user_out,
		const char *fmt,
		size_t len)
{
	static t_ft_printf_spec	spec = {0};

	spec.user_write_output = user_out;
	spec.toprint.buf = (char *)fmt;
	spec.toprint.len = len;
	if (write_op == NULL)
		return (write_stdout(&spec));
	return (write_op(&spec));
}

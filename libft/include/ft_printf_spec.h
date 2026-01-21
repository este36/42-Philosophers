/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spec.h                                    :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:07:15 by emercier          #+#    #+#             */
/*   Updated: 2025/11/17 22:54:43 by emercier       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_SPEC_H
# define FT_PRINTF_SPEC_H

# include <libft.h>
# include <stdarg.h>
# include <stdbool.h>

# define SPEC_FLAG_MINUS	0b000001
# define SPEC_FLAG_ZERO		0b000010
# define SPEC_FLAG_SHARP	0b000100
# define SPEC_FLAG_SPACE	0b001000
# define SPEC_FLAG_PLUS		0b010000
# define SPEC_FLAG_POINT	0b100000
# define HEX_UPPERCASE		1
# define HEX_LOWERCASE		0

typedef struct ft_printf_spec	t_ft_printf_spec;

typedef bool					(*t_apply_precision)(t_ft_printf_spec *spec);
typedef bool					(*t_get_print_buf)(t_ft_printf_spec *spec);
typedef int						(*t_write_op)(t_ft_printf_spec *spec);

typedef struct ft_printf_spec
{
	uint32_t			conversion;
	uint32_t			flags;
	uint32_t			precision;
	uint32_t			min_width;
	void				*user_data;
	void				*user_write_output;
	t_str_ref			val;
	t_str_ref			prec_padding;
	t_str_ref			padding;
	t_str_ref			toprint;
	bool				is_negative;
	t_apply_precision	apply_precision;
	t_get_print_buf		get_print_buf;
	t_write_op			write_cb;
}								t_ft_printf_spec;

void							parse_spec(
									t_ft_printf_spec *spec,
									const char **fmt,
									va_list *arg_list);
int								print_padded(t_ft_printf_spec *spec);
bool							get_prec_padding(t_ft_printf_spec *spec);
bool							merge_prec_padding(t_ft_printf_spec *spec);
bool							apply_precision_int(t_ft_printf_spec *spec);
bool							get_print_buf_int(t_ft_printf_spec *spec);
char							*get_hex(uint64_t n, int uppercase);

int								write_fd(t_ft_printf_spec *spec);
int								write_dstr(t_ft_printf_spec *spec);
int								write_str(t_ft_printf_spec *spec);
int								write_stdout(t_ft_printf_spec *spec);
int								write_raw(
									t_write_op write_op,
									void *user_out,
									const char *fmt,
									size_t len);

int								ft_printf_fn(
									t_write_op write_op,
									void *user_write_output,
									const char *fmt,
									va_list *arg_list);
#endif // FT_PRINTF_SPEC_H

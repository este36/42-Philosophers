/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ops.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:07:15 by emercier          #+#    #+#             */
/*   Updated: 2025/10/24 00:55:53 by emercier         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_OPS_H
# define FT_PRINTF_OPS_H

# include "ft_printf_spec.h"

typedef int	(*t_ft_printf_op)(va_list *, t_ft_printf_spec *);

int	get_digit_count(int n);

int	print_ptr(va_list *arg_list, t_ft_printf_spec *spec);
int	print_char(va_list *arg_list, t_ft_printf_spec *spec);
int	print_int(va_list *arg_list, t_ft_printf_spec *spec);
int	print_str(va_list *arg_list, t_ft_printf_spec *spec);
int	print_hex_upper(va_list *arg_list, t_ft_printf_spec *spec);
int	print_uint(va_list *arg_list, t_ft_printf_spec *spec);
int	print_hex_lower(va_list *arg_list, t_ft_printf_spec *spec);
int	print_percent(va_list *arg_list, t_ft_printf_spec *spec);

#endif // FT_PRINTF_OPS_H

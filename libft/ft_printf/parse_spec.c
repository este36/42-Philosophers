/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:07:15 by emercier          #+#    #+#             */
/*   Updated: 2025/10/24 17:02:39 by emercier         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_spec.h"

uint32_t	parse_uint32(const char **fmt, va_list *arg_list)
{
	uint32_t	res;

	if (**fmt == '*')
	{
		res = (uint32_t)va_arg(*arg_list, unsigned int);
		*fmt += 1;
		return (res);
	}
	res = ft_atoi(*fmt);
	if (**fmt == '-')
		*fmt += 1;
	while (ft_isdigit(**fmt))
		*fmt += 1;
	return (res);
}

void	parse_flag(
		t_ft_printf_spec *spec,
		const char **fmt,
		va_list *arg_list)
{
	if (**fmt == '.')
	{
		spec->flags |= SPEC_FLAG_POINT;
		*fmt += 1;
		spec->precision = parse_uint32(fmt, arg_list);
		return ;
	}
	if (**fmt == '-')
		spec->flags |= SPEC_FLAG_MINUS;
	else if (**fmt == '+')
		spec->flags |= SPEC_FLAG_PLUS;
	else if (**fmt == ' ')
		spec->flags |= SPEC_FLAG_SPACE;
	else if (**fmt == '#')
		spec->flags |= SPEC_FLAG_SHARP;
	else if (**fmt == '0')
		spec->flags |= SPEC_FLAG_ZERO;
	else if (!ft_isdigit(**fmt) && **fmt != '*')
		return ;
	if (!ft_isdigit(**fmt) && **fmt != '*')
		*fmt += 1;
	spec->min_width = parse_uint32(fmt, arg_list);
}

void	parse_spec(t_ft_printf_spec *spec, const char **fmt, va_list *arg_list)
{
	ft_bzero(spec, sizeof(t_ft_printf_spec));
	parse_flag(spec, fmt, arg_list);
	parse_flag(spec, fmt, arg_list);
	spec->conversion = **fmt;
	*fmt += 1;
}

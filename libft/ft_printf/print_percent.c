/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:01:45 by emercier          #+#    #+#             */
/*   Updated: 2025/10/24 02:16:23 by emercier         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_ops.h"
#include <unistd.h> 

int	print_percent(va_list *arg_list, t_ft_printf_spec *spec)
{
	(void)arg_list;
	(void)spec;
	return (write(1, "%", 1));
}

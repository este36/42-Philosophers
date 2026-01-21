/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:07:15 by emercier          #+#    #+#             */
/*   Updated: 2025/12/12 19:13:40 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <libft.h>

int		ft_printf(const char *fmt, ...)	__attribute__((format(printf, 1, 2)));
int		ft_dprintf(int fd,
			const char *fmt, ...)	__attribute__((format(printf, 2, 3)));
int		ft_snprintf(char *str, size_t size,
			const char *fmt, ...)	__attribute__((format(printf, 3, 4)));
int		ft_dsprintf(t_dstr *dstr,
			const char *fmt, ...)	__attribute__((format(printf, 2, 3)));
char	*temp_sprintf(
			const char *fmt, ...)	__attribute__((format(printf, 1, 2)));

#endif // FT_PRINTF_H

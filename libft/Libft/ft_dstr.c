/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:30:36 by emercier          #+#    #+#             */
/*   Updated: 2025/12/15 21:47:57 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	bool	ft_dstr_realloc(t_dstr *dst)
{
	char		*new;
	size_t		new_cap;

	if (dst->cap == 0)
		new_cap = MIN_DSTR_CAP;
	else
		new_cap = dst->cap * 2;
	new = (char *)malloc(sizeof(char) * new_cap);
	if (new == NULL)
		return (false);
	if (dst->buf != NULL)
	{
		ft_strlcpy(new, dst->buf, dst->cap);
		free(dst->buf);
	}
	dst->cap = new_cap;
	dst->buf = new;
	return (true);
}

int	ft_dstr_init(t_dstr *s, size_t cap)
{
	s->cap = cap;
	s->len = 0;
	s->buf = (char *)ft_calloc(1, sizeof(char) * cap);
	if (s->buf == NULL)
	{
		s->cap = 0;
		return (-1);
	}
	return (0);
}

int	ft_dstrcat(t_dstr *dst, char *src)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	while (dst->len + src_len >= dst->cap)
	{
		if (!ft_dstr_realloc(dst))
			return (-1);
	}
	ft_memcpy(dst->buf + dst->len, src, src_len);
	dst->len += src_len;
	return (0);
}

int	ft_dstrncat(t_dstr *dst, char *src, size_t n)
{
	while (dst->len + n >= dst->cap)
	{
		if (!ft_dstr_realloc(dst))
			return (-1);
	}
	ft_memcpy(dst->buf + dst->len, src, n);
	dst->len += n;
	return (0);
}

int	ft_dstrputc(t_dstr *dst, char c)
{
	while (dst->len + 1 >= dst->cap)
	{
		if (!ft_dstr_realloc(dst))
			return (-1);
	}
	dst->buf[dst->len] = c;
	dst->buf[dst->len + 1] = '\0';
	dst->len += 1;
	return (0);
}

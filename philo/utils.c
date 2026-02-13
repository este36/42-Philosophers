/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:41:38 by emercier          #+#    #+#             */
/*   Updated: 2026/02/13 17:25:24 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	new_len;
	void	*new;

	new_len = size * nmemb;
	new = (void *)malloc(new_len);
	if (!new)
		return (NULL);
	memset(new, 0, new_len);
	return ((void *)new);
}

void	*ft_realloc(void *ptr, size_t prev_size, size_t size)
{
	void	*new;

	new = malloc(size);
	if (!new)
		return (NULL);
	ft_memcpy(new, ptr, prev_size);
	free(ptr);
	return (new);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!d && !s)
		return (NULL);
	while (n && ((uintptr_t)d & 7 || (uintptr_t)s & 7))
	{
		*d++ = *s++;
		n--;
	}
	while (n >= 8)
	{
		*((uint64_t *)d) = *((uint64_t *)s);
		d += 8;
		s += 8;
		n -= 8;
	}
	while (n)
	{
		*d++ = *s++;
		n--;
	}
	return (dest);
}

long	now_ms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (-1);
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000L);
}

void	sleep_ms(int ms)
{
	const int	chunk_us = 500;
	int			remaining;

	if (ms <= 0)
		return ;
	remaining = ms * 1000;
	while (remaining > 0)
	{
		if (remaining > chunk_us)
		{
			usleep(chunk_us);
			remaining -= chunk_us;
		}
		else
		{
			usleep(remaining);
			break ;
		}
	}
}

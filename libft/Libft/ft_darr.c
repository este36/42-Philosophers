/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 21:13:59 by emercier          #+#    #+#             */
/*   Updated: 2025/12/15 22:40:19 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_darr_init(t_darr *a, size_t cap, size_t el_size)
{
	ft_bzero(a, sizeof(t_darr));
	a->el_size = el_size;
	a->cap = cap;
	a->arr = ft_calloc((cap + 1), el_size);
	if (a->arr == NULL)
		return (-1);
	return (0);
}

int	ft_darr_push(t_darr *a, void *el)
{
	if (a->len + 1 > a->cap)
	{
		if (a->cap == 0)
		{
			a->cap = MIN_DARR_CAP;
			a->arr = malloc(a->cap * a->el_size);
		}
		else
		{
			a->cap *= 2;
			a->arr = ft_realloc(
					a->arr,
					a->len * a->el_size,
					a->cap * a->el_size);
		}
		if (a->arr == NULL)
			return (-1);
	}
	ft_memcpy((uint8_t *)a->arr + a->len * a->el_size, el, a->el_size);
	a->len++;
	return (0);
}

void	*ft_darr_get(t_darr *a, size_t index)
{
	if (index >= a->len)
		return (NULL);
	return ((uint8_t *)a->arr + index * a->el_size);
}

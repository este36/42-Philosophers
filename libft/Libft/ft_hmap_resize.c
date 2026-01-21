/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmap_resize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 19:55:01 by emercier          #+#    #+#             */
/*   Updated: 2025/12/16 22:45:33 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_hmap.h"

int	ft_hmap_resize(t_hmap *h, size_t new_cap)
{
	t_hmap	tmp;

	tmp = *h;
	tmp.capacity = new_cap;
	tmp.data = ft_calloc(new_cap, tmp.slot_size);
	if (!tmp.data)
		return (-1);
	if (ft_hmap_iter(h, &tmp, (t_hmap_iter_cb)ft_hmap_insert) != 0)
	{
		free(tmp.data);
		return (-1);
	}
	free(h->data);
	*h = tmp;
	return (0);
}

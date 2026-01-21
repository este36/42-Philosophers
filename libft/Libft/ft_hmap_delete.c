/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmap_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 19:55:01 by emercier          #+#    #+#             */
/*   Updated: 2025/12/16 22:45:33 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_hmap.h"

static inline t_hmap__slot	_probe(t_hmap *h, void *key, t_hmap_hash hash)
{
	t_hmap__slot	slot;
	size_t			first_slot_index;
	size_t			i;

	first_slot_index = hash % h->capacity;
	ft_bzero(&slot, sizeof(slot));
	i = 0;
	while (i < h->capacity)
	{
		ft_hmap__slot(h, &slot, (first_slot_index + i) % h->capacity);
		if (*slot.hash == HMAP_SLOT_EMPTY)
			return ((t_hmap__slot){0});
		if (*slot.hash == hash && h->cmp_fn(slot.key, key) == 0)
			return (slot);
		i++;
	}
	return ((t_hmap__slot){0});
}

int	ft_hmap_delete(t_hmap *h, void *key)
{
	t_hmap_hash		hash;
	t_hmap__slot	slot;

	hash = h->hash_fn(key);
	hash |= 2;
	slot = _probe(h, key, hash);
	if (slot.ptr == NULL)
		return (-1);
	*slot.hash = HMAP_SLOT_DELETED;
	return (0);
}

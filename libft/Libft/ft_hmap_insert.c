/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmap_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 19:54:44 by emercier          #+#    #+#             */
/*   Updated: 2025/12/16 22:44:41 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_hmap.h"

static inline t_hmap__slot	_probe(t_hmap *h, void *key, t_hmap_hash hash)
{
	size_t			first_slot_index;
	t_hmap__slot	slot;
	t_hmap__slot	tomb;
	size_t			i;

	first_slot_index = hash % h->capacity;
	i = 0;
	ft_bzero(&slot, sizeof(slot));
	ft_bzero(&tomb, sizeof(tomb));
	while (i < h->capacity)
	{
		ft_hmap__slot(h, &slot, (first_slot_index + i) % h->capacity);
		if ((*slot.hash == hash && h->cmp_fn(slot.key, key) == 0))
			return (slot);
		if (tomb.ptr == NULL && *slot.hash == HMAP_SLOT_DELETED)
			tomb = slot;
		else if (tomb.ptr != NULL && *slot.hash == HMAP_SLOT_EMPTY)
			return (tomb);
		else if (*slot.hash == HMAP_SLOT_EMPTY)
			return (slot);
		i++;
	}
	return (tomb);
}

int	ft_hmap_insert(t_hmap *h, void *key, void *val)
{
	t_hmap_hash		hash;
	t_hmap__slot	slot;

	hash = h->hash_fn(key);
	hash |= 2;
	slot = _probe(h, key, hash);
	if (slot.ptr == NULL)
	{
		if (ft_hmap_resize(h, h->capacity * 2) != 0)
			return (-1);
	}
	ft_memcpy(slot.hash, &hash, sizeof(t_hmap_hash));
	ft_memcpy(slot.key, key, h->key_size);
	ft_memcpy(slot.val, val, h->val_size);
	return (0);
}

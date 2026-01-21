/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 21:13:00 by emercier          #+#    #+#             */
/*   Updated: 2025/12/17 00:29:40 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_hmap.h"
#include <stdalign.h>

void	ft_hmap__slot(t_hmap *h, t_hmap__slot *slot, size_t index)
{
	slot->index = index;
	slot->ptr = h->data + (slot->index * h->slot_size);
	slot->hash = (slot->ptr + h->hash_off);
	slot->key = (slot->ptr + h->key_off);
	slot->val = (slot->ptr + h->val_off);
}

int	ft_hmap_iter(t_hmap *h, void *user_data, t_hmap_iter_cb fn)
{
	t_hmap__slot	slot;
	size_t			i;

	ft_bzero(&slot, sizeof(slot));
	i = 0;
	while (i < h->capacity)
	{
		ft_hmap__slot(h, &slot, i);
		if (*slot.hash > HMAP_SLOT_DELETED)
		{
			if (fn(user_data, slot.key, slot.val) != 0)
				return (-1);
		}
		i++;
	}
	return (0);
}

int	ft_hmap_init(t_hmap *h, size_t cap, size_t key_size, size_t val_size)
{
	const size_t	_a = alignof(max_align_t) - 1;

	if (!h || val_size == 0)
		return (-1);
	ft_bzero(h, sizeof(*h));
	h->hash_fn = (t_hmap_hash_fn)str_ref_hash;
	h->cmp_fn = (t_hmap_cmp_fn)str_ref_cmp;
	h->capacity = cap;
	if (h->capacity == 0)
		h->capacity = 256;
	h->key_size = key_size;
	if (h->key_size == 0)
		h->key_size = sizeof(t_str_ref);
	h->val_size = val_size;
	h->hash_off = 0;
	h->key_off = (sizeof(t_hmap_hash) + _a) & ~(_a);
	h->val_off = (h->key_off + h->key_size + _a) & ~(_a);
	h->slot_size = (h->val_off + h->val_size + _a) & ~(_a);
	h->data = ft_calloc(h->capacity, h->slot_size);
	if (h->data == NULL)
		return (-1);
	return (0);
}

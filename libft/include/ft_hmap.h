/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmap.h                                           :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:07:15 by emercier          #+#    #+#             */
/*   Updated: 2025/11/17 22:54:43 by emercier       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HMAP_H
# define FT_HMAP_H

# include <stddef.h>
# include <stdint.h>
# include "libft.h"

enum e_hmap_slot_state
{
	HMAP_SLOT_EMPTY,
	HMAP_SLOT_DELETED,
	HMAP_SLOT_OCCUPIED,
};

typedef uint64_t		t_hmap_hash;
typedef struct s_hmap	t_hmap;
typedef t_hmap_hash		(*t_hmap_hash_fn)(void *key);
typedef int				(*t_hmap_cmp_fn)(void *, void *);
typedef int				(*t_hmap_iter_cb)(void *, void *, void *);

typedef struct s_hmap
{
	uint8_t			*data;
	size_t			capacity;
	size_t			hash_off;
	size_t			key_size;
	size_t			key_off;
	size_t			val_size;
	size_t			val_off;
	size_t			slot_size;
	t_hmap_hash_fn	hash_fn;
	t_hmap_cmp_fn	cmp_fn;
}	t_hmap;

typedef struct s_hmap__slot
{
	void		*ptr;
	size_t		index;
	t_hmap_hash	*hash;
	void		*key;
	void		*val;
}	t_hmap__slot;

int			ft_hmap_init(
				t_hmap *h,
				size_t cap,
				size_t key_size,
				size_t val_size);

int			ft_hmap_insert(t_hmap *h, void *key, void *val);
int			ft_hmap_delete(t_hmap *h, void *key);
void		*ft_hmap_get(t_hmap *h, void *key);
int			ft_hmap_resize(t_hmap *h, size_t new_cap);
t_hmap_hash	str_ref_hash(t_str_ref *key);

int			ft_hmap_iter(
				t_hmap *h,
				void *user_data,
				t_hmap_iter_cb fn);

void		ft_hmap__slot(t_hmap *h, t_hmap__slot *slot, size_t index);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_ref.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <emercier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:55:17 by emercier          #+#    #+#             */
/*   Updated: 2025/12/16 14:08:18 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_hmap.h"

int	str_ref_cmp(t_str_ref *s1, t_str_ref *s2)
{
	if (s1->len != s2->len)
		return (s1->len - s2->len);
	return (ft_memcmp(s1->buf, s2->buf, s1->len));
}

t_str_ref	c_str_ref(const char *s)
{
	return ((t_str_ref){.buf = (char *)s, .len = ft_strlen(s)});
}

t_hmap_hash	str_ref_hash(t_str_ref *key)
{
	t_hmap_hash	hash;
	size_t		i;

	i = 0;
	hash = 5381;
	while (i < key->len)
	{
		hash = ((hash << 5) + hash) + (uint8_t)key->buf[i];
		i++;
	}
	return (hash);
}

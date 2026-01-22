/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                      +:+                   */
/*   By: emercier <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/11/18 19:10:45 by emercier       #+#    #+#                */
/*   Updated: 2026/01/21 21:06:17 by emercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

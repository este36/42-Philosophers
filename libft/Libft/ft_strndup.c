/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_strndup.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: emercier <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/11/17 19:35:38 by emercier       #+#    #+#                */
/*   Updated: 2025/11/17 19:36:26 by emercier       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, const size_t s_len)
{
	char	*res;

	if (s_len == 0)
		return (NULL);
	res = malloc(s_len + 1);
	if (!res)
		return (NULL);
	ft_memcpy(res, s, s_len);
	res[s_len] = '\0';
	return (res);
}

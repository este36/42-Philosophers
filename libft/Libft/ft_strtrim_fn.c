/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_strtrim_fn.c                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: emercier <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/11/11 19:06:07 by emercier       #+#    #+#                */
/*   Updated: 2025/11/11 19:08:49 by emercier       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim_fn(char const *s1, int (*fn)(int c))
{
	size_t	s1_len;
	size_t	res_index;
	size_t	res_len;

	s1_len = ft_strlen(s1);
	res_index = 0;
	res_len = s1_len;
	while (res_index < s1_len)
	{
		if (!fn(s1[res_index]))
			break ;
		res_index++;
	}
	while (res_len > res_index)
	{
		if (!fn(s1[res_len - 1]))
			break ;
		res_len--;
	}
	res_len -= res_index;
	return (ft_substr(s1, res_index, res_len));
}

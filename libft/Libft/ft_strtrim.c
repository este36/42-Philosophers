/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:52:33 by emercier          #+#    #+#             */
/*   Updated: 2025/09/30 19:52:35 by emercier         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	is_from_set(int c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (true);
		i++;
	}
	return (false);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_len;
	size_t	res_index;
	size_t	res_len;

	s1_len = ft_strlen(s1);
	res_index = 0;
	res_len = s1_len;
	while (res_index < s1_len)
	{
		if (!is_from_set(s1[res_index], set))
			break ;
		res_index++;
	}
	while (res_len > res_index)
	{
		if (!is_from_set(s1[res_len - 1], set))
			break ;
		res_len--;
	}
	res_len -= res_index;
	return (ft_substr(s1, res_index, res_len));
}

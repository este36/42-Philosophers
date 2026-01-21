/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                          :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:53:40 by emercier          #+#    #+#             */
/*   Updated: 2025/11/28 17:29:17 by emercier       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_substr_count(char const *s, char c)
{
	size_t	substr_count;
	size_t	pos;
	char	*next_delimiter;

	substr_count = 0;
	pos = 0;
	if (c == '\0')
		return (1);
	while (s[pos])
	{
		next_delimiter = ft_strchr(s + pos, c);
		if (next_delimiter == NULL)
		{
			substr_count++;
			break ;
		}
		if ((next_delimiter - (s + pos)) != 0)
		{
			substr_count++;
			pos = (next_delimiter - s);
		}
		pos++;
	}
	return (substr_count);
}

static char	*get_next_substr(char const *s, char c, size_t *pos)
{
	char	*next_delimiter;
	char	*res;
	size_t	res_len;

	next_delimiter = (char *)s + *pos;
	while (s[*pos])
	{
		next_delimiter = ft_strchr(s + *pos, c);
		if (next_delimiter == NULL)
			next_delimiter = (char *)(s + *pos) + ft_strlen(s + *pos);
		if (next_delimiter - (s + *pos) != 0)
		{
			res_len = next_delimiter - (s + *pos);
			res = ft_substr(s, *pos, res_len);
			if (!res)
				return (NULL);
			res[res_len] = '\0';
			*pos += res_len;
			return (res);
		}
		*pos += 1;
	}
	return (NULL);
}

static int	alloc_substrs(char **dst, const size_t substr_count,
					char const *s, char c)
{
	size_t	dst_pos;
	size_t	s_pos;
	char	*next_substr;

	dst_pos = 0;
	s_pos = 0;
	while (dst_pos < substr_count)
	{
		next_substr = get_next_substr(s, c, &s_pos);
		if (!next_substr)
			return (-1);
		dst[dst_pos] = next_substr;
		dst_pos++;
	}
	return (0);
}

void	str_arr_free(char **strs)
{
	size_t	i;

	i = 0;
	if (!strs)
		return ;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	substr_count;
	char	**res;

	substr_count = get_substr_count(s, c);
	res = ft_calloc((substr_count + 1), sizeof(char *));
	if (!res)
		return (NULL);
	if (*s == '\0' && c == '\0')
		return (res);
	if (alloc_substrs(res, substr_count, s, c) != 0)
	{
		str_arr_free((char **)res);
		free(res);
		return (NULL);
	}
	return (res);
}

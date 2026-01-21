/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                     :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 20:04:24 by emercier          #+#    #+#             */
/*   Updated: 2025/11/17 19:37:44 by emercier       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "libft.h"
#include "get_next_line.h"

static bool	init_state(
				t_gnl_state *state,
				int fd,
				t_str_ref *acc)
{
	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		if (acc->buf != NULL)
		{
			free(acc->buf);
			ft_memset(acc, 0, sizeof(t_str_ref));
		}
		return (false);
	}
	if (acc->buf == NULL)
	{
		acc->buf = malloc(1);
		if (!acc->buf)
			return (false);
		acc->buf[0] = '\0';
	}
	ft_memset(state, 0, sizeof(t_gnl_state));
	state->read.buf = malloc(BUFFER_SIZE);
	if (!state->read.buf)
		return (false);
	state->acc = acc;
	return (true);
}

static bool	accumulate(t_gnl_state *state)
{
	ssize_t	total_len;
	char	*tmp;

	if (state->read.len == 0)
		return (true);
	total_len = state->acc->len + state->read.len;
	tmp = malloc(total_len);
	if (!tmp)
	{
		free(state->read.buf);
		return (false);
	}
	ft_memcpy(tmp, state->acc->buf, state->acc->len);
	ft_memcpy(tmp + state->acc->len, state->read.buf, state->read.len);
	free(state->acc->buf);
	state->acc->buf = tmp;
	state->acc->len = total_len;
	return (true);
}

static char	*get_line(t_gnl_state *state)
{
	char	*res;
	char	*tmp;

	if (state->read.len == 0 && state->found.len == 0)
	{
		res = ft_strndup(state->acc->buf, state->acc->len);
		free(state->acc->buf);
		ft_memset(state->acc, 0, sizeof(t_str_ref));
		return (res);
	}
	res = ft_strndup(state->found.buf, state->found.len);
	tmp = malloc(state->acc->len - state->found.len);
	if (!tmp || !res)
	{
		free(res);
		free(tmp);
		return (NULL);
	}
	ft_memcpy(tmp, state->acc->buf + state->found.len,
		state->acc->len - state->found.len);
	free(state->acc->buf);
	state->acc->buf = tmp;
	state->acc->len = state->acc->len - state->found.len;
	return (res);
}

static bool	line_found(t_gnl_state *state)
{
	const char	*nl_char = ft_memchr(state->acc->buf, '\n', state->acc->len);

	if (!nl_char)
		return (false);
	state->found.buf = state->acc->buf;
	state->found.len = nl_char - state->acc->buf + 1;
	return (true);
}

char	*get_next_line(int fd)
{
	static t_str_ref	acc = {0};
	t_gnl_state			state;
	char				*res;

	if (!init_state(&state, fd, &acc))
		return (NULL);
	while (!line_found(&state))
	{
		state.read.len = read(fd, state.read.buf, BUFFER_SIZE);
		if (state.read.len == (size_t) - 1)
		{
			free(state.read.buf);
			free(state.acc->buf);
			ft_memset(state.acc, 0, sizeof(t_str_ref));
			return (NULL);
		}
		if (state.read.len == 0)
			break ;
		if (!accumulate(&state))
			return (NULL);
	}
	res = get_line(&state);
	free(state.read.buf);
	return (res);
}

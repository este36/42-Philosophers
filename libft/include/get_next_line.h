/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                     :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 20:07:13 by emercier          #+#    #+#             */
/*   Updated: 2025/11/17 19:37:25 by emercier       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_gnl_state
{
	t_str_ref	*acc;
	t_str_ref	read;
	t_str_ref	found;
}	t_gnl_state;

char	*get_next_line(int fd);

#endif // GET_NEXT_LINE_H

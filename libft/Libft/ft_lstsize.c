/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:31:37 by emercier          #+#    #+#             */
/*   Updated: 2025/10/02 15:31:57 by emercier         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	size;
	t_list	*tail;

	size = 0;
	tail = lst;
	while (tail && size < 0x7fffffff)
	{
		tail = tail->next;
		size++;
	}
	return (size);
}

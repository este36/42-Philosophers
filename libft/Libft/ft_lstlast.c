/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:30:46 by emercier          #+#    #+#             */
/*   Updated: 2025/10/02 15:31:05 by emercier         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tail;

	if (!lst)
		return (NULL);
	tail = lst;
	while (1)
	{
		if (!tail->next)
			return (tail);
		tail = tail->next;
	}
}

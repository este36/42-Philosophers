/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:29:51 by emercier          #+#    #+#             */
/*   Updated: 2025/10/02 15:30:05 by emercier         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*to_free;
	t_list	*tail;

	if (!lst || !del)
		return ;
	tail = *lst;
	while (tail)
	{
		to_free = tail;
		tail = tail->next;
		to_free->next = NULL;
		del(to_free->content);
		free(to_free);
	}
	*lst = NULL;
}

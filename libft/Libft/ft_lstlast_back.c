/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:30:36 by emercier          #+#    #+#             */
/*   Updated: 2025/10/02 21:03:17 by emercier         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstlast_back(t_list **lst, t_list *new)
{
	t_list	*tail;

	if (!lst)
		return ;
	tail = ft_lstlast(*lst);
	if (tail)
	{
		tail->next = new;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emercier <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:31:08 by emercier          #+#    #+#             */
/*   Updated: 2025/10/02 15:31:20 by emercier         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*new_tail;

	if (!lst)
		return (NULL);
	new = ft_lstnew(NULL);
	if (!new)
		return (NULL);
	new_tail = new;
	while (lst)
	{
		new_tail->content = f(lst->content);
		if (lst->next)
		{
			new_tail->next = ft_lstnew(NULL);
			if (!new_tail->next)
			{
				ft_lstclear(&new, del);
				break ;
			}
			new_tail = new_tail->next;
		}
		lst = lst->next;
	}
	return (new);
}

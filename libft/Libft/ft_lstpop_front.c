/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_lstpop_front.c                                   :+:    :+:           */
/*                                                      +:+                   */
/*   By: emercier <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/11/18 13:25:13 by emercier       #+#    #+#                */
/*   Updated: 2025/11/19 14:50:34 by emercier       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpop_front(t_list **lst)
{
	t_list	*prev_head;

	if (*lst == NULL)
		return (NULL);
	prev_head = *lst;
	*lst = (*lst)->next;
	prev_head->next = NULL;
	return (prev_head);
}

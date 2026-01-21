/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_lstpop_back.c                                    :+:    :+:           */
/*                                                      +:+                   */
/*   By: emercier <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/11/18 13:29:13 by emercier       #+#    #+#                */
/*   Updated: 2025/11/18 17:10:47 by emercier       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpop_back(t_list **lst)
{
	t_list	*head;
	t_list	*prev_tail;

	head = *lst;
	while (head)
	{
		if (head->next != NULL && head->next->next == NULL)
		{
			prev_tail = head->next;
			head->next = NULL;
			return (prev_tail);
		}
		head = head->next;
	}
	return (*lst);
}

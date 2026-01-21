/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_lstrot_back.c                                    :+:    :+:           */
/*                                                      +:+                   */
/*   By: emercier <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/11/18 13:35:18 by emercier       #+#    #+#                */
/*   Updated: 2025/11/21 14:26:57 by emercier       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrot_back(t_list **lst)
{
	t_list	*head;
	t_list	*start;

	start = *lst;
	head = *lst;
	while (head)
	{
		if (head->next != NULL && head->next->next == NULL)
		{
			if (head == start)
			{
				*lst = head->next;
				(*lst)->next = start;
				(*lst)->next->next = NULL;
				return ;
			}
			head->next->next = start;
			*lst = head->next;
			head->next = NULL;
			return ;
		}
		head = head->next;
	}
}

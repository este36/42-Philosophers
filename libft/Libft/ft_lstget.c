/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_lstget.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: emercier <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/11/18 14:50:51 by emercier       #+#    #+#                */
/*   Updated: 2025/11/18 16:48:09 by emercier       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstget(t_list *lst, size_t index)
{
	size_t	i;

	i = 0;
	while (lst && i < index)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}

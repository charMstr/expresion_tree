/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstuniq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:02:31 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/15 13:02:43 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** note:	This function will remove any duplicate link from the linked list.
**			A duplicate is a link whose content is exactly the same as a
**			previously met link, according to the custome cmp function.
** note:	use case of cmp: cmp(t_list*->content, t_list*->content);
*/

void	ft_lstuniq(t_list **alst, int (*cmp)(), void (*del)(void *))
{
	t_list **current;
	t_list *next;

	if (!alst || !(*alst) || !cmp || !del)
		return ;
	current = &(*alst)->next;
	while (*alst && *current)
	{
		next = (*current)->next;
		if (!cmp((*alst)->content, (*current)->content))
		{
			ft_lstdelone(*current, del);
			*current = next;
		}
		else
			current = &(*current)->next;
		if (!*current)
		{
			alst = &(*alst)->next;
			if (!*alst)
				return ;
			current = &(*alst)->next;
		}
	}
}

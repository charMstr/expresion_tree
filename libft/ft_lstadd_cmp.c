/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_cmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:33:16 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/14 00:10:30 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** note:	this function will insert in the linked list a new link and keep it
**			sorted, thanks to a cmp function.
**
** note:	cmp could be ft_strcmp... if its return is  <= to zero. we insert
**			the link in place.
*/

void	ft_lstadd_cmp(t_list **alst, t_list *new, int (*cmp)())
{
	if (!alst || !new || !cmp)
		return ;
	while (*alst)
	{
		if (cmp((*alst)->content, new->content) <= 0)
			break;
		alst = &(*alst)->next;
	}
	new->next = *alst;
	*alst = new;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_cmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:33:16 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/14 00:10:30 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** note:	this function will remove in the list all links in which content is
**			matching with the data_ref argument, according to the cmp function.
**
** note:	cmp could be ft_strcmp... it returns zero when we need to delete
**			the matching link.
**
** note:	the del function is passed along to the ft_lst_delone function
*/

void	ft_lstdel_cmp(t_list **alst, void *data_ref, int (*cmp)(), \
		void (*del)(void *))
{
	t_list *to_del;
	t_list *next;

	if (!alst || !(*alst) || !del || !cmp || !data_ref)
		return ;
	while (*alst)
	{
		to_del = *alst;
		next = (*alst)->next;
		if (!cmp((*alst)->content, data_ref))
		{
			ft_lstdelone(to_del, del);
			*alst = next;
		}
		else
			alst = &(*alst)->next;
	}
}

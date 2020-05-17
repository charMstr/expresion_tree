/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:33:16 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/14 00:10:30 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** note:	first arg should be the ADDRESS (&...) of an existing link
**			or a pointer to a linked list head (therefore a t_list ** pointer)
**
** note:	the del function is passed along to the ft_lst_delone function
*/

void	ft_lstdel_front(t_list **alst, void	(*del)(void *))
{
	t_list *to_del;

	if (!alst || !(*alst) || !del)
		return ;
	to_del = *alst;
	*alst = (*alst)->next;
	ft_lstdelone(to_del, del);
}

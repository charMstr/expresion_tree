/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2019/11/11 15:02:30 by charmstr          #+#    #+#             */
/*   updated: 2019/11/14 20:51:11 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** note:	this function extract from the linked list the first link whose
**			content matched the content_ref arg.
** note:	if you want to find the lind without modifying the linked list,
**			refer to ft_lstfind()
**
** return:	null if not found.
*/

t_list *ft_lstget(t_list **alst, void *content_ref, int (*cmp)())
{
	t_list *extract;

	if (!cmp || !alst || !(*alst) || !content_ref)
		return (NULL);
	while (*alst)
	{
		if (0 == cmp(content_ref, (*alst)->content))
		{
			extract = *alst;
			*alst = (*alst)->next;
			return (extract);
		}
		alst = &(*alst)->next;
	}
	return (NULL);
}

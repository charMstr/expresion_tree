/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2019/11/11 15:02:30 by charmstr          #+#    #+#             */
/*   updated: 2019/11/14 20:51:11 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** note:	this function returns a pointer to the first link whose content
**			matched the content_ref arg.
** note:	if you want to get the link, and extract it from the linked list at
**			the same time. use ft_lstget()
**
** return:	null if not found.
*/

t_list *ft_lstfind(t_list *alst, void *content_ref, int (*cmp)())
{
	if (!cmp || !alst || !content_ref)
		return (NULL);
	while (alst)
	{
		if (0 == cmp(content_ref, alst->content))
			return (alst);
		alst = alst->next;
	}
	return (NULL);
}

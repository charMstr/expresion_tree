/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget_front.c                                  :+:      :+:    :+:   */
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
** note:	this function will pop the head of the list, and return that link,
**			after setting its next to NULL.
**
** RETURN:	front link.
**			NULL if list was empty of wrong inputs.
*/

t_list	*ft_lstget_front(t_list **alst)
{
	t_list *to_get;

	if (!alst || !(*alst))
		return NULL;
	to_get = *alst;
	*alst = (*alst)->next;
	to_get->next = NULL;
	return (to_get);
}


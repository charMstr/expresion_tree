/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget_back.c                                   :+:      :+:    :+:   */
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
**			or a pointer to a linked list (therefore a t_list ** pointer)
**
** note:	this function will pop the last link of the list, and return it,
**			after setting its previous to NULL.
**
** RETURN:	last link.
**			NULL if list was empty of wrong inputs.
*/

t_list	*ft_lstget_back(t_list **alst)
{
	t_list *to_get;

	if (!alst || !(*alst))
		return (NULL);
	while (*alst)
	{
		to_get = *alst;
		if (!(*alst)->next)
		{
			*alst = NULL;
			return (to_get);
		}
		alst = &(*alst)->next;
	}
	return (NULL);
}

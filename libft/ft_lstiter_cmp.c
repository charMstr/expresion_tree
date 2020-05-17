/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_cmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:02:31 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/15 13:02:43 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** note:	iteration of f function on CONTENTS of evrey links that match
**			content_ref, according to function cmp().
**
** note2: f itself needs to deal with the case lst->content == NULL;
*/

void	ft_lstiter_cmp(t_list *lst, void (*f)(void *), int (*cmp)(), \
		void *content_ref)
{
	if (!lst || !f || !cmp || !content_ref)
		return ;
	while (lst)
	{
		if (!cmp(content_ref, lst->content))
			(*f)(lst->content);
		lst = lst->next;
	}
}

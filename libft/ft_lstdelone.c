/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:49:12 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/11 16:47:00 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** note:	if we want to extract a link that is in the middle of a list,
**			reconnecting the previous and the following link should be done
**			before calling this function, therefore content->next is never free
**
** note:	the (*del) function shoud be written specific to content
*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		if (del)
			del(lst->content);
		free(lst);
	}
}

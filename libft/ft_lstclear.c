/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:47:24 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/11 18:59:41 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** note:	deletes link and all following ones: different from ft_lstdelone
**
** note:	this function can delete an linked list thats stucked in a loop.
**			However the very first link has to be part of the loop.
**			Refer to ft_lstloop_proof()
**
** note:	if you want to delete from the middle of the list:
**			-	it puts the pointer to NULL so it ends the list here.
**			-	1st arg: &(previous->next) should be used to NULLify the
**				correct pointer.
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	**then;
	t_list	**copy;

	copy = lst;
	if (*copy)
		copy = &(*copy)->next;
	while (*copy)
	{
		if ((*lst) == (*copy))
			break ;
		then = &(*copy)->next;
		ft_lstdelone(*copy, del);
		copy = then;
	}
	ft_lstdelone(*lst, del);
	*lst = NULL;
}

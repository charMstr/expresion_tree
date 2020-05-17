/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:46:31 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/15 00:31:08 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** note:	iteration of (*f) on each link in order to creat a new list.
**			See ft_lstiter if you want to modify the original.
**
** note:	(*del) is passed to ft_lstclear, then to ft_lstdelone to clean the
**			whole new_list if a malloc failed in ft_lstnew.
**
** note:	if you want to duplicate the link list (and its content). you will
**			need to cread an f function that duplicates(malloc) content.
**
** RETURN:	a new list, modified version according to (*f) function
**			NULL if original is NULL or failure in malloc.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_link;
	void	*new_content;

	new_list = NULL;
	if (!(*f) || !lst || !del)
		return (NULL);
	while (lst)
	{
		if (!(new_content = (*f)(lst->content)))
		{
			ft_lstclear(&new_list, (*del));
			return (NULL);
		}
		if (!(new_link = ft_lstnew(new_content)))
		{
			ft_free((void **)&new_content);
			ft_lstclear(&new_list, (*del));
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_link);
		lst = lst->next;
	}
	return (new_list);
}

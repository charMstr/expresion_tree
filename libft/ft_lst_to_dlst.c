/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_dslt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:02:31 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/15 13:02:43 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** note:	this function will translate a simple linked list into a double
**			linked list.
**
** note:	the single link list remains untouched. the contents are duplicated
**			thanks to a custom dup_content() func.
**
** note:	if failure in mallocs, the newly created list is destroyed.
**
** RETURN:	t_dlist * pointer
**			NULL if failure
*/

t_dlist *ft_lst_to_dlst(t_list *lst, void *(*dup_content)(void *), \
		void (*del)(void *))
{
	t_dlist *head;
	t_dlist *new;
	void	*content;

	head = NULL;
	if (!(*dup_content) || !lst || !del)
		return (NULL);
	while (lst)
	{
		if (!(content = dup_content(lst->content)))
		{
			ft_dlstclear(&head, del);
			return (NULL);
		}
		if (!(new = ft_dlstnew(content)))
		{
			ft_free((void **)&content);
			ft_dlstclear(&head, del);
			return (NULL);
		}
		ft_dlstadd_back(&head, new);
		lst = lst->next;
	}
	return (head);
}

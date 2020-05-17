/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_to_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:33:16 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/14 00:10:30 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** note:	this function will translate a 2 dimensions array of char* into a
**			t_list
** note:	if array was empty (first char* equal to NULL). we still creat one
***			link.
**
** RETURN:	NULL if failure, or array was NULL.
**			t_list*
*/

t_list	*ft_array_to_lst(const char **array)
{
	char	*str;
	t_list	*head;
	t_list	*new;

	head = NULL;
	if (!array || (-1 == ft_array_len(array)))
		return (NULL);
	while (*array)
	{
		if (!(str = ft_strdup(*array)) || !(new = ft_lstnew(str)))
		{
			ft_lstclear(&head, free);
			return (NULL);
		}
		ft_lstadd_back(&head, new);
		array++;
	}
	return (head);
}

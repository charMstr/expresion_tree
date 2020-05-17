/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:02:30 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/14 20:51:11 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** note:	this function will merge lst2 inside alst1, repceting the sorted
**			order imposed by the cmp function.
** note:	lst2 and alst1 should have been sorted previously.
** note:	if alst1 is NULL: we end up with alst1 pointing to lst2 once sorted
*/

void ft_lstmerge(t_list **alst1, t_list *lst2, int (*cmp)())
{
	t_list	**head_copy;
	t_list	*lst2_next_cpy;

	if (!alst1 || !lst2 || !cmp)
		return ;
	head_copy = alst1;
	while (*alst1 && lst2)
	{
		if (cmp((*alst1)->content, lst2->content) <= 0)
		{
			lst2_next_cpy = lst2->next;
			lst2->next = *alst1;
			*alst1 = lst2;
			lst2 = lst2_next_cpy;
			alst1 = head_copy;
		}
		else
			alst1 = &(*alst1)->next;
	}
	ft_lstadd_back(alst1, lst2);
}

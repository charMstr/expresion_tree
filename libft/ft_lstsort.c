/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2019/11/11 15:02:30 by charmstr          #+#    #+#             */
/*   updated: 2019/11/14 20:51:11 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** note:	this function will sort the list according to a cmp function
** note:	use of the cmp function:
**			(*cmp)(list_ptr->content, other_list_ptr->content);
*/

void	ft_lstsort(t_list **alst, int (*cmp)())
{
	t_list **sniffer;
	t_list *current;

	if (!cmp || !alst || !(*alst))
		return ;
	sniffer = alst;
	while (*sniffer)
	{
		if (!(*sniffer)->next)
			return ;
		if (cmp((*sniffer)->content, (*sniffer)->next->content) < 0)
		{
			current = *sniffer;
			*sniffer = (*sniffer)->next;
			current->next = (*sniffer)->next;
			(*sniffer)->next = current;
			sniffer = alst;
		}
		else
			sniffer = &(*sniffer)->next;
	}
}

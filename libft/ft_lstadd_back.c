/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:02:30 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/14 20:51:11 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** input:	- arg1: head of list, (ex: &head)
**			- arg2: new link to be added
**
** note:	can be used as a lstjoin. just put lst2 in second argument.
** note:	if *alst is NULL, it means the list was empty. new becomes the head
*/

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	if (!alst || !new)
		return ;
	while (*alst)
		alst = &(*alst)->next;
	*alst = new;
}

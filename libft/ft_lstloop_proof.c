/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstloop_proof.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:02:31 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/15 13:02:43 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** note:	this function will determine if linked list is an infinite loop
**
** RETURN:	0 stuck in Loop
**			1 ok or NULL argument
*/

int	ft_lstloop_proof(t_list *turtle)
{
	t_list *rabbit;

	if (!turtle || !(turtle->next))
		return (1);
	rabbit = turtle->next->next;
	while (turtle && rabbit)
	{
		if (!rabbit->next)
			return (1);
		rabbit = rabbit->next->next;
		turtle = turtle->next;
		if (turtle == rabbit)
			return (0);
	}
	return (1);
}

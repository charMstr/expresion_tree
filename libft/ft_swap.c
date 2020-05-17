/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:49:23 by charmstr          #+#    #+#             */
/*   Updated: 2019/12/19 19:05:58 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** note:	This function will swap two things, pointed to by the ptr_things*.
**			The size argument is the result of the sizeof operator.
**
** note:	cannot be used with static memory (but works on address of static
**			memory). so always add the & operator in front of a string.
**
** examples:
**			ft_swap(&int_a, &int_b, sizeof(int));
**			ft_swap(&str1, &str2, sizeof(char *));
**			ft_swap(&link1->content, &link2->content, sizeof(content*));
**			ft_swap(link1_ptr, link2_ptr, sizeof(t_list));
**
*/

void	ft_swap(void *ptr_thing1, void *ptr_thing2, int size_pointed_thing)
{
	int	i;

	i = 0;
	while (i < size_pointed_thing)
	{
		*((char *)ptr_thing1) ^= *((char *)ptr_thing2);
		*((char *)ptr_thing2) ^= *((char *)ptr_thing1);
		*((char *)ptr_thing1) ^= *((char *)ptr_thing2);
		i++;
		ptr_thing1++;
		ptr_thing2++;
	}
}

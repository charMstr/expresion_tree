/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:30:31 by charmstr          #+#    #+#             */
/*   Updated: 2020/01/30 15:58:34 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** note:	this function will free a two dimensional char array and set all
**			pointers to NULL.
** input:	- ptr:	the address of a two dimension array to be freed (&array)
**			- k:	the index from wich to start decreasing.
**					or simply ft_array_len().
**
** exemple:	ft_array_free(&array, ft_array_len((const char*)array));
**
** RETURN:	NULL for context convenience
*/

void	*ft_array_free(char ***ptr, int k)
{
	while (--k >= 0)
		ft_free((void**)&(ptr[0][k]));
	ft_free((void**)ptr);
	return (NULL);
}

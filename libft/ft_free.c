/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:23:04 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/12 16:23:07 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** note:	give the address of the pointer you want to free, so that we can
**			set the pointer itself to NULL.
*/

void	ft_free(void **ptr)
{
	if (!ptr)
		return ;
	free(*ptr);
	*ptr = NULL;
}

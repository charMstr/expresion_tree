/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_debug.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:33:16 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/14 00:10:30 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** note:	simply a debug funtcion to display the content of a 2 dimensions
**			char* array.
*/

void	ft_array_debug(char **str)
{
	ft_putendl_fd("ARRAY DEBUG:", 2);
	if (!str)
	{
		ft_putendl_fd("array is empty", 2);
		return ;
	}
	while (*str)
	{
		ft_putendl_fd(*str, 2);
		str++;
	}
}

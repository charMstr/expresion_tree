/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:23:04 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/12 16:23:07 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** note:	this function is not protected against null strings input.
** note:	refer to ft_strncmp() for a partial comparaison.
**
** RETURN:	0 if strictly equal and same length.
*/

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return ((unsigned)s1[i] - (unsigned)s2[i]);
}

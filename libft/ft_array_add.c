/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:33:16 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/14 00:10:30 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** note:	this function will extend the old array, making space for a new
**			string. The array's content is placed in the new pointer and only
**			the pointer to old array is freed.
**
** note:	If failure while malloc, the entire array if freed. Otherwise
**
** note:	a duplicate of str is made within the function. therefor no matter
**			what, the str should be freed if previously malloced.
**
** note:	pointer to new_array. (ontly the pointer to array is freed).
**			NULL (array is freed)
*/

char	**ft_array_add(char **array, char *str)
{
	char	*str_dup;
	char	**new_array;
	int		size_new;

	if (!(str_dup = ft_strdup(str)))
	{
		ft_array_free(&array, ft_array_len((const char**)array));
		return (NULL);
	}
	size_new = ft_array_len((const char **)array) + 1;
	if (size_new == 0)
		size_new++;
	if (!(new_array = (char **)malloc(sizeof(char *) * (size_new + 1))))
	{
		free(str_dup);
		ft_array_free(&array, ft_array_len((const char**)array));
		return (NULL);
	}
	new_array[size_new] = NULL;
	new_array[--size_new] = str_dup;
	while (--size_new >= 0)
		new_array[size_new] = array[size_new];
	ft_free((void**)&array);
	return (new_array);
}

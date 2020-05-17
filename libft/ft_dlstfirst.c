#include "libft.h"

/*
** RETURN:	pointer to very first link
**			NULL if the head of list pointer was NULL
*/

t_dlist	*ft_dlstfirst(t_dlist *lst)
{
	if (lst)
		while (lst->previous)
			lst = lst->previous;
	return (lst);
}

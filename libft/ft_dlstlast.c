#include "libft.h"

/*
** RETURN:	pointer to very last link
**			NULL if the head of list pointer was NULL
*/

t_dlist	*ft_dlstlast(t_dlist *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}


#include "libft.h"

/*
** note:	if we want to extract a link that is in the middle of a list,
**			reconnecting the previous and the following link should be done
**			before calling this function, therefore content->next and
**			content->previous are never freed.
**
** note:	the (*del) function shoud be written specific to content
*/

void	ft_dlstdelone(t_dlist *lst, void (*del)(void *))
{
	if (lst)
	{
		if (del)
			del(lst->content);
		free(lst);
	}
}

#include "libft.h"

/*
** note:	deletes element and all following ones: different from ft_lstdelone
**
** note:	if you want to delete from the middle of the list:
**			it will go up and down the stream (using previous and next).
*/

void	ft_dlstclear(t_dlist **lst, void (*del)(void *))
{
	t_dlist	*current;
	t_dlist	*then;

	if (!lst || !del)
		return ;
	if (*lst)
	{
		current = (*lst)->next;
		while (current)
		{
			then = current->next;
			ft_dlstdelone(current, del);
			current = then;
		}
	}
	current = *lst;
	while (current)
	{
		then = current->previous;
		ft_dlstdelone(current, del);
		current = then;
	}
	*lst = NULL;
}

#include "libft.h"

/*
** note:	this function will delete the front link of the double linked list.
**			see ft_dlstpop_back as well.
*/

void	ft_dlstdel_front(t_dlist **head, void (*del)(void*))
{
	t_dlist *new_head;

	if (!head || !del || !*head)
		return ;
	new_head = (*head)->next;
	ft_dlstdelone(*head, del);
	*head = NULL;
	*head = new_head;
}

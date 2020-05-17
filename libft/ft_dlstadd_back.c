#include "libft.h"

/*
** input:	- arg1: head of list, (ex: &head)
**			- arg2: new link to be added
**
** note2:	if *alst is NULL, it means the list was empty. new list is created
*/

void	ft_dlstadd_back(t_dlist **alst, t_dlist *new)
{
	t_dlist *tmp;
	t_dlist *previous;

	if (!alst || !new)
		return ;
	if (!(*alst))
	{
		*alst = new;
		return ;
	}
	tmp = *alst;
	while (tmp->next)
	{
		previous = tmp;
		tmp = tmp->next;
	}
	tmp->next = new;
	new->previous = tmp;
}

#include "libft.h"

/*
** input:	- arg1: head of list (ex: &head)
**			- arg2: new link to be added
**
** note2:	if *alst is NULL, it means the list was empty. new list is created
*/

void	ft_dlstadd_front(t_dlist **alst, t_dlist *new)
{
	if (!alst || !new)
		return ;
	if (*alst)
	{
		(*alst)->previous = new;
		new->next = *alst;
	}
	*alst = new;
}

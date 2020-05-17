#include "libft.h"

/*
** note: next = NULL, previous = NULL, content = the argument
** note: if content is NULL it doesnt mather it is still created as is.
**
** RETURN:	new link that was malloced
**			NULL pointer if failure
*/

t_dlist	*ft_dlstnew(void *content)
{
	t_dlist *new;

	if (!(new = (t_dlist *)malloc(sizeof(*new))))
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->previous = NULL;
	return (new);
}

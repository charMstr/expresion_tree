#include "infix_to_rpn.h"

/*
** note:	this function will creat a new t_list *link, that contains a
**			t_token *pointer, itself having its type set to OPERAND_INT and the
**			thing.operand_int set to -1.
**
** RETURN:	t_list *link
**			NULL malloc failure
*/

t_list	*create_link_with_minus_one_token(void)
{
	t_list	*new_link;
	t_token	*new_token;

	if (!(new_token = malloc(sizeof(t_token))))
		return (NULL);
	new_token->type = OPERAND_INT;
	new_token->thing.operand_int = -1;
	if (!(new_link = ft_lstnew(new_token)))
	{
		free(new_token);
		return (NULL);
	}
	return (new_link);
}

/*
** note:	this function will creat a new t_list *link, that contains a
**			t_token *pointer, itself having its type set to R_BRACE
**
** RETURN:	t_list *link
**			NULL malloc failure
*/

t_list *create_link_with_rbrace_token(void)
{
	t_list	*new_link;
	t_token	*new_token;

	if (!(new_token = malloc(sizeof(t_token))))
		return (NULL);
	new_token->type = R_BRACE;
	if (!(new_link = ft_lstnew(new_token)))
	{
		free(new_token);
		return (NULL);
	}
	return (new_link);
}

/*
** note:	this function will creat a new t_list *link, that contains a
**			t_token *pointer, itself having its type set to OPERATOR and its
**			thing.op set to MUL.
**
** RETURN:	t_list *link
**			NULL malloc failure
*/

t_list *create_link_with_mul_token(void)
{
	t_list	*new_link;
	t_token	*new_token;

	if (!(new_token = malloc(sizeof(t_token))))
		return (NULL);
	new_token->type = OPERATOR;
	new_token->thing.op = MUL;
	if (!(new_link = ft_lstnew(new_token)))
	{
		free(new_token);
		return (NULL);
	}
	return (new_link);
}

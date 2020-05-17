#include "infix_to_rpn.h"

/*
** note:	this function will take care of the case when the very first
**			non whitespace character is an operator sign. we only allow the
**			sign to be SUB ('-'), otherwise we consider it a parser error.
** note:	in the case of a minus. we will insert a token containing 0, and
**			a token containing then minus operator.
**
** note:	this function is a quick fix to end the project.
**
** RETURN:	1 OK
**			0 KO
*/

int	very_first_char_is_operator(t_list **token_list, char *str, int i)
{
	t_list	*new_link1;
	t_list	*new_link2;
	char 	*zero;

	if (str[i] != '-')
		return (0);
	if (!(zero = ft_strdup("0")))
		return (0);
	if (!(new_link1 = creat_token_link_operand_str(zero)))
	{
		free(zero);
		return (0);
	}
	if (!(new_link2 = creat_token_link_operator(str[i])))
	{
		free(zero);
		free(new_link1);
		return (0);
	}
	ft_lstadd_front(token_list, new_link2);
	ft_lstadd_front(token_list, new_link1);
	return (1);
}

/*
** note:	this function will creat a t_list *containing a token that is an
**			operator.
**
** RETURN:	pointer
**			NULL if failure
*/

t_list	*creat_token_link_operator(char operator)
{
	t_list	*new_link;
	t_token	*new_token;

	if (!(new_token = malloc(sizeof(t_token))))
		return (NULL);
	new_token->type = OPERATOR;
	new_token->thing.op = operator;
	if (!(new_link = ft_lstnew(new_token)))
	{
		free(new_token);
		return (NULL);
	}
	return (new_link);
}

/*
** note: 	this function will creat t_list * containg a token that is an
**			operand str.
**
** RETURN:	pointer
**			NULL if failure
*/

t_list *creat_token_link_operand_str(char *str)
{
	t_list	*new_link;
	t_token	*new_token;

	if (!(new_token = malloc(sizeof(t_token))))
		return (NULL);
	new_token->type = OPERAND_STR;
	new_token->thing.operand_str = str;
	if (!(new_link = ft_lstnew(new_token)))
	{
		free(new_token);
		return (NULL);
	}
	return (new_link);
}

/*
** note:	this function will return true if the portion of the string is
**			whitespaces only.
**
** RETURN:	1 OK
**			0 KO, or null input
*/

int		iswhitespaces_only(char *str, int start, int len)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[start + i] && i < len)
	{
		if (str[start + i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

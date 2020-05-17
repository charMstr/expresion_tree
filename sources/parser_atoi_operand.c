#include "infix_to_rpn.h"

/*
** note:	this function will check each time we met an operand_str that is it
**			valid. it is not valid if there is numeric characters, then
**			non_numeric characters(whitespaces), then numeric characters again.
**			or if before or after the numeric characters, we meet non numeric
**			characters that are not whitespaces.
**
** RETURN:	1 ok
**			0 KO
*/

int	parser_operand_str(t_list *tokens)
{
	while (tokens)
	{
		if (((t_token*)(tokens->content))->type == OPERAND_STR)
		{
			if (!(valid_opstr(((t_token*)(tokens->content))->\
							thing.operand_str)))
				return (0);
			operand_str_to_int((t_token*)(tokens->content));
		}
		tokens = tokens->next;
	}
	return (1);
}

/*
** note:	this function assists the parser_operand_str function
**
** RETURN:	1 OK
**			0 KO
*/

int		valid_opstr(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			break;
		i++;
	}
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}


/*
** note:	this function will go over the token list, each time we meet at
**			token of type operand_str, we convert it to operand_int.
*/

void	operand_str_to_int(t_token *token)
{
	char *tmp;

	token->type = OPERAND_INT;
	tmp = token->thing.operand_str;
	token->thing.operand_int = ft_atoi(token->thing.operand_str);
	free(tmp);
}

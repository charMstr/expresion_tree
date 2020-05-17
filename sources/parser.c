#include "infix_to_rpn.h"

/*
** note:	this function will parse the token list, calling different
**			subfunctions.
*/

int	parser(t_list **tokens)
{
	if (!parser_2_op_in_a_row(*tokens))
		return (0);
	if (!parser_assist1(*tokens))
		return (0);
	if (!parser_assist2(tokens))
		return (0);
	if (!parser_assist3(*tokens))
		return (0);
	if (!parser_assist4(*tokens))
		return (0);
	if (!parser_operand_str(*tokens))
		return (0);
	if (!parser_infix_to_rpn(tokens))
		return (0);
	return (1);
}

/*
**	note:	this function will loop over the linked list, and check the
**			relation between the current token and the next one.
**	note:	separate cases when current is an operator or not. and also if
**			current->next is NULL or not.
**
** RETURN:	1 OK
**			0 KO
*/

int	parser_assist1(t_list *tokens)
{
	while (tokens)
	{
		if (((t_token*)(tokens->content))->type == OPERATOR)
		{
			if (!tokens->next || \
					!parser_next_to_operator((t_token *)(tokens->content), \
					(t_token*)(tokens->next->content)))
				return (0);
		}
		else
		{
			if (tokens->next && \
				!parser_next_to_non_operator((t_token *)(tokens->content), \
					(t_token*)(tokens->next->content)))
				return (0);
			else if (!tokens->next \
				&& !parser_next_to_non_operator((t_token *)(tokens->content), \
							NULL))
				return (0);
		}
		tokens = tokens->next;
	}
	return (1);
}


/*
** note:	this function will check to we never meet more than 2 operators in
**			a row.
**
** RUTURN: 1 OK
**			0 KO
*/

int	parser_2_op_in_a_row(t_list *tokens)
{
	int count;

	count = 0;
	while (tokens)
	{
		if (((t_token*)(tokens->content))->type == OPERATOR)
			count++;
		if (((t_token*)(tokens->content))->type == OPERAND_STR \
				|| ((t_token*)(tokens->content))->type == OPERAND_INT \
				|| ((t_token*)(tokens->content))->type == L_BRACE \
				|| ((t_token*)(tokens->content))->type == R_BRACE )
			count = 0;
		if (count == 3)
		{
			printf("more than 2 operators in a row\n");
			return (0);
		}
		tokens = tokens->next;
	}
	return (1);
}

/*
** note:	this funciton will check that the current token relatively to the
**			next one, when the current is an operator
** note:	we know from here that the next is not NULL, because we would have
**			previously returned 0.
**
** note:	all those conditions are strictly the same. an operator has to be
**			followed either by a left brace, an operand or a minus sign.
**
** RETURN:	1 OK
**			0 KO
*/

int	parser_next_to_operator(t_token *current, t_token *next)
{
	if (current->thing.op == SUB && (next->type != L_BRACE && next->type \
			!= OPERAND_STR && next->type == OPERATOR && next->thing.op != SUB))
	{
		printf("near - (after a '-' operator)\n");
		return (0);
	}
	else if (current->thing.op == ADD && (next->type != L_BRACE && next->type \
			!= OPERAND_STR && next->type == OPERATOR && next->thing.op != SUB))
	{
		printf("near + (after a '+' operator)\n");
		return (0);
	}
	else if (current->thing.op == MUL && (next->type != L_BRACE && next->type \
			!= OPERAND_STR && next->type == OPERATOR && next->thing.op != SUB))
	{
		printf("near * (after a '*' operator)\n");
		return (0);
	}
	else if (current->thing.op == DIV && (next->type != L_BRACE && next->type \
			!= OPERAND_STR && next->type == OPERATOR && next->thing.op != SUB))
	{
		printf("near / (after a '/' operator)\n");
		return (0);
	}
	else if (current->thing.op == EXP && (next->type != L_BRACE && next->type \
			!= OPERAND_STR && next->type == OPERATOR && next->thing.op != SUB))
	{
		printf("near ^ (after a '^' operator)\n");
		return (0);
	}
	return (1);
}

/*
** note:	this function will check that the current token is doing ok with
**			the followoing one.
**
** RETURN:	1 OK
**			0 KO
*/

int	parser_next_to_non_operator(t_token *current, t_token *next)
{
	if (current->type == OPERAND_STR && next && (next->type == L_BRACE \
			|| next->type == OPERAND_STR))
	{
		printf("near operand (after an operand)\n");
		return (0);
	}
	if (current->type == L_BRACE && (!next || next->type == R_BRACE \
			|| (next->type == OPERATOR && next->thing.op != SUB)))
	{
		printf("near left brace (after a left brace)\n");
		return (0);
	}
	if (current->type == R_BRACE && next && (next->type == OPERAND_STR \
				|| next->type == L_BRACE))
	{
		printf("near right brace (after a right brace)\n");
		return (0);
	}
	return (1);
}

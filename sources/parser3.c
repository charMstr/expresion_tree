#include "infix_to_rpn.h"

/*
** note:	this function will take care of the special case when we have
**			a succession of the tokens: OPERATOR(either MUL, DIV, or EXP)
**			and then SUB. example "... *- ...".
**
** note:	we basically have three cases.
**			1) the next thing is an operand, we insert four new_tokens:
**			L_BRACE, OPERAND_INTEGER(value = -1), MUL, and after the operand.
**			R_BRACE.
**			2) the next thing is a left brace.
**				2a). if the next token is a SUB. we simply delete this token.
**				2b). we insert two new tokens: OPERAND_INTEGER(value = -1), MUL
**
** note:	at this stage, we consider we already have taken care of the cases
**			when we have for example "2 +- 3" , or "- -3", so no need to worry
**			about the associativity being broken.
**
** note:	we return 0 if this situation happens at the very begining.
**
** RETURN:	1 OK
**			0 KO, failure while mallocing space for the extra token.
*/

int		parser_assist3(t_list *tokens)
{
	int	situation;
	int res;

	if (is_operator_sub_combo(tokens, &situation))
	{
		printf("operator/sub combo at the begining.\n");
		return (0);
	}
	while (tokens)
	{
		if (is_operator_sub_combo(tokens, &situation))
		{
			if (situation == 1)
				res = op_sub_combo_situation1(tokens);
			else if (situation == 2)
				res = op_sub_combo_situation2(tokens);
			if (!res)
				return (0);
		}
		tokens = tokens->next;
	}
	return (1);
}

/*
** note:	this function is here for the sake of clarity. it returns true if
**			we are in the case of an operator(at this stage it can only be
**			either: MUL, DIV, or EXP), immediately followed by a SUB operator.
**
** note:	we know at this stage that we cannot have a linked list ending by
**			an operator. and we know that we cannot have more than two
**			operators in a row.
*/

int		is_operator_sub_combo(t_list *link, int *situation)
{
	t_list *next2;

	if (((t_token *)(link->content))->type == OPERATOR)
	{
		if (((t_token *)(link->next->content))->type == OPERATOR \
			&& ((t_token*)(link->next->content))->thing.op == SUB)
		{
			next2 = link->next->next;
			if (((t_token *)(next2->content))->type == OPERAND_STR)
				*situation = 1;
			else if (((t_token *)(next2->content))->type == L_BRACE)
				*situation = 2;
			return (1);
		}
	}
	return (0);
}

/*
** note:	this function will be called in the case we had an operator
**			followed by SUB operator, and followed by an operand token.
**
** note:	we will have to surround the following operand by parenthesis, and
**			add a token -1 and a token MUL
*/

int		op_sub_combo_situation1(t_list *token)
{
	t_list *tmp_1;
	t_list *tmp_2;
	t_list *operand;

	operand = token->next->next;
	((t_token*)token->next->content)->type = L_BRACE;
	if (!(tmp_2 = create_link_with_minus_one_token()))
		return (0);
	token->next->next =  tmp_2;
	tmp_2->next = operand;
	if (!(tmp_1 = create_link_with_mul_token()))
		return (0);
	tmp_2->next =  tmp_1;
	tmp_1->next = operand;
	if (!(tmp_2 = create_link_with_rbrace_token()))
		return (0);
	tmp_1 = operand->next;
	operand->next =  tmp_2;
	tmp_2->next = tmp_1;
	return (1);
}

/*
** note:	this function will be called in the case we had an operator
**			followed by SUB operator, and followed by a L_BRACE.
**
** note:	we will have to surround the following brace pair by new extra
**			parenthesis, and add a token -1 and a token MUL
**
** RETURN: 1
*/

int		op_sub_combo_situation2(t_list *token)
{
	t_list *tmp_1;
	t_list *tmp_2;
	t_list *l_brace;

	l_brace = token->next->next;
	((t_token*)token->next->content)->type = L_BRACE;
	if (!(tmp_2 = create_link_with_minus_one_token()))
		return (0);
	token->next->next =  tmp_2;
	tmp_2->next = l_brace;
	if (!(tmp_1 = create_link_with_mul_token()))
		return (0);
	tmp_2->next =  tmp_1;
	tmp_1->next = l_brace;
	if (!(tmp_2 = create_link_with_rbrace_token()))
		return (0);
	if (!(tmp_1 = find_matching_right_brace(l_brace)))
		return (0);
	l_brace = tmp_1->next;
	tmp_1->next = tmp_2;
	tmp_2->next = l_brace;
	return (1);
}

/*
** note:	this function will find the link corresponding to the matching
**			left parenthesis given as argument.
**
** RETURN:	pointeur to t_list element.
**			NULL
*/

t_list *find_matching_right_brace(t_list *tokens)
{
	int depth;

	depth = 0;
	while (tokens)
	{
		if (((t_token*)tokens->content)->type == L_BRACE)
			depth++;
		else if (((t_token*)tokens->content)->type == R_BRACE)
			depth--;
		if (!depth)
			return (tokens);
		tokens = tokens->next;
	}
	printf("while solving a situation like \"*-\": uneven parenthesis\n");
	return (NULL);
}

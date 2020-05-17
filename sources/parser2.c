#include "infix_to_rpn.h"

/*
** note:	this function will take care of the case when we meet an operator
**			ADD, immediately followed by a SUB. or When we meet two sub in a
**			row. first case, will set the first_is_add to one. we then delete
**			the + token and only leave the - token.
**			Second case sets the firs_is_add to 0. we then delete the current
**			token as well, but set the next one to + (ADD).
**
** note:	error can occur if case one happens at the very beginning of the
**			tokens list.
**
** RETURN:	1 OK
** 			0 KO
*/

int	parser_assist2(t_list **tokens)
{
	t_list *tmp;
	int first_is_add;

	if (is_combo_add_sub(*tokens, &first_is_add) && first_is_add)
	{
		printf("cannot have +- at the begining\n");
		return (0);
	}
	while (*tokens)
	{
		if (is_combo_add_sub(*tokens, &first_is_add))
		{
			tmp = *tokens;
			if (!first_is_add)
				((t_token*)((*tokens)->next->content))->thing.op = ADD;
			*tokens = (*tokens)->next;
			free_token_content(tmp->content);
			free(tmp);
		}
		else
			tokens = &(*tokens)->next;
	}
	return (1);
}

/*
** note:	this function is here for the sake of clarity. it returns true if
**			we are in the case of a ADD operator, immediately followed by a SUB
**			operator (and sets the first_is_add to one.) or if we are in the
**			case of two successive SUB operator.
*/

int		is_combo_add_sub(t_list *tokens, int *first_is_add)
{
	if (((t_token *)(tokens->content))->type == OPERATOR \
		&& ((t_token*)(tokens->content))->thing.op == ADD)
	{
		if (tokens->next \
			&& (((t_token *)(tokens->next->content))->type == OPERATOR \
			&& ((t_token*)(tokens->next->content))->thing.op == SUB))
		{
			*first_is_add = 1;
			return (1);
		}
	}
	else if (((t_token *)(tokens->content))->type == OPERATOR \
		&& ((t_token*)(tokens->content))->thing.op == SUB)
	{
		if (tokens->next \
			&& (((t_token *)(tokens->next->content))->type == OPERATOR \
			&& ((t_token*)(tokens->next->content))->thing.op == SUB))
		{
			*first_is_add = 0;
			return (1);
		}
	}
	return (0);
}

/*
** note:	this function will take care of the special case when we have
**			a succession of the tokens: L_BRACE and SUB or "(-...", we insert a
**			token thats going to contain a negative 1 in between, and we
**			change the SUB into a MUL. so it becomes "(-1 *...".
**
** note:	at this stage, we consider we already have taken care of the cases
**			when we have for example "2 *- 3" , or "2 *- (-3)", so we might
**			have added or remved parenthesis.
**
** RETURN:	1 OK
**			0 KO, failure while mallocing space for the extra token.
*/

int		parser_assist4(t_list *tokens)
{
	t_list *new;
	t_list *successor;

	while (tokens)
	{
		if (is_lbrace_sub_combo(tokens))
		{
			if (!(new = create_link_with_minus_one_token()))
				return (0);
			successor = tokens->next;
			tokens->next = new;
			new->next = successor;
			((t_token*)(successor->content))->thing.op = MUL;
			tokens = successor;
		}
		tokens = tokens->next;
	}
	return (1);
}

/*
** note:	this function is here for the sake of clarity: it returns true in
**			the case of a succesion of L_BRACE, and SUB tokens.
** RETURN:	1 COMBO
**			0 no COMBO.
*/

int		is_lbrace_sub_combo(t_list *tokens)
{
	if (((t_token *)(tokens->content))->type == L_BRACE)
	{
		if (tokens->next \
			&& (((t_token *)(tokens->next->content))->type == OPERATOR \
			&& ((t_token*)(tokens->next->content))->thing.op == SUB))
			return (1);
	}
	return (0);
}

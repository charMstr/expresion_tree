#include "infix_to_rpn.h"

/*
** this file will translate from the infix notation, into the rpn (postfix)
** notation. using a stack (one pass).
*/

/*
** note:	this function will loop over the tokens list, using the stack as a
**			mean of algorithm. and returning a linked list in the rpn notation
**			of token with operators and operands. braces are eliminated.
**
** note:	when entering the function: we wont encounter the type OPERAND_STR
**			anymore at this stage.
**
** RETURN:	t_list rpn linked list
**			NULL if (failure)
*/

t_list *parser_infix_to_rpn(t_list **tokens)
{
	t_list *stack;
	t_list *rpn;

	stack = NULL;
	rpn = NULL;
	while (*tokens)
	{
		if (((t_token*)(*tokens)->content)->type == OPERAND_INT)
			ft_lstadd_back(&rpn, ft_lstget_front(tokens));
		else if (((t_token*)(*tokens)->content)->type == R_BRACE \
				|| ((t_token*)(*tokens)->content)->type == L_BRACE)
		{
			if (!infix_to_rpn_braces(tokens, &rpn, &stack))
				return (NULL);
		}
		else if (((t_token*)(*tokens)->content)->type == OPERATOR)
			infix_to_rpn_operator(tokens, &rpn, &stack);
	}
	if (!unpile_stack_to_rpn(stack, &rpn))
		return (NULL);
	*tokens = rpn;
	return (*tokens);
}


/*
** note:	This function will unpile the stack into the rpn at the very end.
**			Failure occurs when there is still some opening braces in the stack
**
** note:	if failure: we free all the linked lists. but tokens is empty if we
**			exited the Main loop already.
**
** RETURN:	1 OK
**			0 KO
*/

int		unpile_stack_to_rpn(t_list *stack, t_list **rpn)
{
	while (stack)
	{
		if (((t_token*)stack->content)->type == L_BRACE)
		{
			free_token_list(*rpn);
			free_token_list(stack);
			printf("too many left parenthesis\n");
			return (0);
		}
		ft_lstadd_back(rpn, ft_lstget_front(&stack));
	}
	return (1);
}


/*
** note:	this function takes care of the case when we have a parenthesis.
**
** note:	if there is a problem with the parenthesis mismatching, we return 0
**			and we free stack and rpn;
**
** RETURN:	1 ok
**			0 failure.
*/

int		infix_to_rpn_braces(t_list **tokens, t_list **rpn, t_list **stack)
{
	if (((t_token*)(*tokens)->content)->type == L_BRACE)
		ft_lstadd_front(stack, ft_lstget_front(tokens));
	else
	{
		free_link_and_token(ft_lstget_front(tokens));
		while (*stack && ((t_token*)(*stack)->content)->type != L_BRACE)
			ft_lstadd_back(rpn, ft_lstget_front(stack));
		if (!*stack)
		{
			free_token_list(*rpn);
			free_token_list(*tokens);
			*tokens = NULL;
			printf("too many right parenthesis\n");
			return (0);
		}
		else
			free_link_and_token(ft_lstget_front(stack));
	}
	return (1);
}

/*
** note:	this function is handling an operator, deciding if we add it to the
**			stack, or to depile the stack into rpn until we can add it onto the
**			stack, eventually.
*/

void	infix_to_rpn_operator(t_list **tokens, t_list **rpn, t_list **stack)
{
	if (((t_token*)(*tokens)->content)->thing.op == ADD \
		|| ((t_token*)(*tokens)->content)->thing.op == SUB)
	{
		while (*stack && ((t_token*)(*stack)->content)->type != L_BRACE)
			ft_lstadd_back(rpn, ft_lstget_front(stack));
		ft_lstadd_front(stack, ft_lstget_front(tokens));
	}
	if (((t_token*)(*tokens)->content)->thing.op == MUL \
		|| ((t_token*)(*tokens)->content)->thing.op == DIV)
	{
		while (*stack && ((t_token*)(*stack)->content)->type != L_BRACE \
				&& ((t_token*)(*stack)->content)->thing.op != ADD \
				&& ((t_token*)(*stack)->content)->thing.op != SUB)
			ft_lstadd_back(rpn, ft_lstget_front(stack));
		ft_lstadd_front(stack, ft_lstget_front(tokens));
	}
	if (((t_token*)(*tokens)->content)->thing.op == EXP)
		ft_lstadd_front(stack, ft_lstget_front(tokens));
}

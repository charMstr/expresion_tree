#include "infix_to_rpn.h"

/*
** note:	this function will take care of the Main loop while building the
**			expression tree from our token list
**
** RETURN:	t_bc_nodes* OK
**			NULL if KO
*/

t_bc_nodes *build_tree(t_list **token_list)
{
	t_list *stack;
	t_list *link;
	t_bc_nodes *root;

	stack = NULL;
	while (*token_list)
	{
		link = ft_lstget_front(token_list);
		if (!(consume_token(link, &stack)))
		{
			ft_lstclear(&stack, free_tree);
			free_token_list(*token_list);
			free_link_and_token(link);
			return (NULL);
		}
		free_link_and_token(link);
	}
	root = (t_bc_nodes*)(stack->content);
	free(stack);
	return (root);
}

/*
** note:	this function will use one token and either add it to the stack,
**			(operand) or get the too first operand of the stack and insert it
**			into the tree (operator).
**
** RETURN:	1 OK
**			0 KO
*/

int	consume_token(t_list *link, t_list **stack)
{
	if (((t_token*)link->content)->type == OPERAND_INT)
	{
		if (!(add_node_operand_to_stack(stack, \
						((t_token *)link->content)->thing.operand_int)))
			return (0);
	}
	else if (((t_token*)link->content)->type == OPERATOR)
	{
		if (!(add_node_operator_to_stack(stack, \
						((t_token *)link->content)->thing.op)))
			return (0);
	}
	return (1);
}

/*
** note:	this function is in charge of creating a node for the current
**			operator, and setting both its child as the two first nodes found
**			onto the stack. the operator node_itself being finally pushed onto
**			the stack.
**
** RETURN:	1 OK
**			0 KO
*/

int	add_node_operator_to_stack(t_list **stack, type_op op)
{
	t_list *first;
	t_list *second;
	t_bc_nodes *left;
	t_bc_nodes *right;
	t_bc_nodes *node;

	first = ft_lstget_front(stack);
	right = (t_bc_nodes*)first->content;
	free(first);
	second = ft_lstget_front(stack);
	left = (t_bc_nodes*)second->content;
	if (!(node = creat_operator_node(op, right, left)))
	{
		free_tree(right);
		free_tree(left);
		free(second);
		return (0);
	}
	second->content = node;
	ft_lstadd_front(stack, second);
	return (1);
}

/*
** note:	this function is in charge of adding the node to the existing stack
**
** RETURN:	1 ok
**			0 KO
*/

int	add_node_operand_to_stack(t_list **stack, int operand)
{
	t_bc_nodes *node;
	t_list *new;

	if (!(node = creat_operand_node(operand)))
		return (0);
	if (!(new = ft_lstnew(node)))
	{
		free(node);
		return (0);
	}
	ft_lstadd_front(stack, new);
	return (1);
}

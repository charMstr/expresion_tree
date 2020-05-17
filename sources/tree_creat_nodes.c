#include "infix_to_rpn.h"

/*
** note:	this function will creat a new operand node for the expression tree
**
** RETURN:	t_bc_nodes OK
**			NULL KO
*/

t_bc_nodes *creat_operand_node(int operand)
{
	t_bc_nodes *node;

	if (!(node = malloc(sizeof(t_bc_nodes))))
		return (NULL);
	node->tag = OPERAND_NODE;
	node->taged.integer = operand;
	return (node);
}

/*
** note:	this function will creat a new operator node for the expression
**			tree
**
** RETURN:	t_bc_nodes OK
**			NULL KO
*/

t_bc_nodes *creat_operator_node(type_op op, t_bc_nodes* right, \
		t_bc_nodes* left)
{
	t_bc_nodes *operator;

	if (!(operator = malloc(sizeof(t_bc_nodes))))
		return (NULL);
	operator->tag = OPERATOR_NODE;
	operator->taged.operator_exp.op = op;
	operator->taged.operator_exp.left = left;
	operator->taged.operator_exp.right = right;
	return (operator);
}

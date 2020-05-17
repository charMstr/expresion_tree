#include "infix_to_rpn.h"

/*
** note:	this funcition will either return the value contained in an operand
**			node or enter a recurcive function that takes care of the
**			operations that needs to be applied.
*/

int	calculate_tree(t_bc_nodes *root)
{
	int left_num;
	int right_num;

	if (root->tag == OPERATOR_NODE)
	{
		right_num = calculate_tree(root->taged.operator_exp.right);
		left_num = calculate_tree(root->taged.operator_exp.left);
		return (calculate_operator(root->taged.operator_exp.op, left_num, \
				right_num));
	}
	else
		return (root->taged.integer);
}

/*
** note:	this function will operate the right calculation depending on the
**			operator_id given.
**
** RETURN:	calculated expression.
*/

int	calculate_operator(type_op op, int left, int right)
{
	int res;

	if (op == ADD)
		return (left + right);
	else if (op == SUB)
		return (left - right);
	else if (op == DIV)
		return (left /right);
	else if (op == MUL)
		return (left * right);
	else if (op == EXP)
	{
		if (!right)
			return (0);
		res = 1;
		while (right)
		{
			res = res * left;
			if (right > 0)
				right--;
			else
				right++;
		}
		return (res);
	}
	return (0);
}

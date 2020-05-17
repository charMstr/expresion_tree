#include "infix_to_rpn.h"

/*
** note:	this function will debug the token_list when we exit the
**			tokenize_infix() func.
*/

void	debug_token_list(t_list *token_list)
{
	printf("\n===============================================================================\n");
	printf("================== DEBUG TOKEN LIST ===========================================\n");

	if (!token_list)
	{
		printf("token_list was empty!\n");
	}
	while (token_list)
	{
		if (((t_token*)(token_list->content))->type == OPERAND_STR)
		{
			printf("type is: OPERAND_STR\n");
			printf("\tstr is: [%s]\n", \
					((t_token*)(token_list->content))->thing.operand_str);
		}
		if (((t_token*)(token_list->content))->type == OPERAND_INT)
		{
			printf("type is: ORERAND_INT\n");
			printf("\tint is: [%d]\n", \
					((t_token*)(token_list->content))->thing.operand_int);
		}
		if (((t_token*)(token_list->content))->type == OPERATOR)
		{
			printf("type is: OPERATOR\n");
			printf("\toperator is: %c\n", \
					((t_token*)(token_list->content))->thing.op);
		}
		if (((t_token*)(token_list->content))->type == L_BRACE)
			printf("type is: L_BRACE\n");
		if (((t_token*)(token_list->content))->type == R_BRACE)
			printf("type is: R_BRACE\n");
		token_list = token_list->next;
	}
	printf("===============================================================================\n\n");
}

/*
** this function will display the tree inorder
*/

void	debug_tree(t_bc_nodes *tree, int is_root)
{
	char c;

	if (!tree)
		return ;
	if (tree->tag == OPERATOR_NODE)
	{
		if (tree->taged.operator_exp.op == ADD)
			c = '+';
		else if (tree->taged.operator_exp.op == SUB)
			c = '-';
		else if (tree->taged.operator_exp.op == DIV)
			c = '/';
		else if (tree->taged.operator_exp.op == MUL)
			c = '*';
		else
			c = '^';
		debug_tree(tree->taged.operator_exp.left, 0);
		if (is_root)
			printf("this is the root of the tree...\n");
		printf("operator contains: [%c]\n", c);
		debug_tree(tree->taged.operator_exp.right, 0);
	}
	else
	{
		if (is_root)
			printf("this is the root of the tree...\n");
		printf("operand contains: [%d]\n", tree->taged.integer);
	}
}

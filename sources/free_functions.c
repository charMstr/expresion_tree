#include "infix_to_rpn.h"

/*
** note:	the two following functions will free the token_list and its
**			content.
** RETURN:	void * for norminette purpose.
*/

void	*free_token_list(t_list *token_list)
{
	ft_lstclear(&token_list, free_token_content);
	return (NULL);
}

/*
** note:	this function will free a link of the linked list, and its token
**			content.
*/

void		free_link_and_token(t_list *token)
{
	free_token_content(token->content);
	free(token);
}

/*
** note:	this function will be called either by fr_lstclear, or by
**			free_link_and_token().
*/

void 	free_token_content(void *token)
{
	t_token *recast_token;

	recast_token = (t_token*)token;
	if (!recast_token)
		return ;
	if (recast_token->type == OPERAND_STR)
		free(recast_token->thing.operand_str);
	free(recast_token);
}

/*
** note:	this function will parcour the tree and destroy each node.
**			it is also a call back function used by ft_lstclear(), called when
**			the stack containing the t_bc_nodes needs to be destroyed.
*/

void	free_tree(void *node)
{
	t_bc_nodes *root;

	root = (t_bc_nodes*)node;
	if (root->tag == OPERATOR_NODE)
	{
		free_tree(root->taged.operator_exp.left);
		free_tree(root->taged.operator_exp.right);
	}
	free(root);
}


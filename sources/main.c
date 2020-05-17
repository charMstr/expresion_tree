#include "infix_to_rpn.h"

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	t_list		*token_list;
	t_bc_nodes	*tree;
	int			res;

	if (argc != 2)
	{
		printf("need to enter a infix match expression\n");
		return (0);
	}
	if (!(token_list = tokenize_infix(argv[1])))
	{
		printf("empty string or failure while tokenizing\n");
		return (0);
	}
//	printf("tokenization was ok...\n");
//	debug_token_list(token_list);
	if (!parser(&token_list))
	{
		printf("\033[31m parser error:\033[0m\n");
		free_token_list(token_list);
		return (0);
	}
//	printf("parsing was ok...\n");
//	debug_token_list(token_list);
	tree = build_tree(&token_list);
	//debug_tree(tree, 1);
	res = calculate_tree(tree);
	printf("result: %d\n", res);
	return (0);
}
